#define BUTTON_PIN 2      // Pin الذي يتصل بالزر
#define TRANSISTOR_PIN 8  // Pin الذي يتحكم في الترانزستور
#define AUTO_OFF_DELAY 10000 // الوقت بالميلي ثانية لإيقاف الجهاز تلقائيًا

unsigned long lastPressTime = 0;
unsigned long currentMillis;
bool deviceState = false; // لتخزين حالة الجهاز (تشغيل/إيقاف)
bool buttonState = false;
bool lastButtonState = false;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP); // الزر يتم استخدامه كمدخل مع مقاومة سحب عالية
  pinMode(TRANSISTOR_PIN, OUTPUT);   // الترانزستور كمخرج
  digitalWrite(TRANSISTOR_PIN, LOW); // بدء الجهاز في وضع إيقاف
  Serial.begin(9600);
}

void loop() {
  currentMillis = millis();
  buttonState = digitalRead(BUTTON_PIN);

  // إذا تم الضغط على الزر (الانتقال من HIGH إلى LOW)
  if (buttonState == LOW && lastButtonState == HIGH) {
    delay(50); // تأخير لمنع الاهتزاز (debouncing)
    lastPressTime = currentMillis;
    deviceState = !deviceState; // تغيير حالة الجهاز (تشغيل/إيقاف)
    digitalWrite(TRANSISTOR_PIN, deviceState ? HIGH : LOW); // تشغيل أو إيقاف الجهاز
  }

  // إيقاف الجهاز تلقائيًا بعد فترة معينة
  if (deviceState && (currentMillis - lastPressTime >= AUTO_OFF_DELAY)) {
    deviceState = false;
    digitalWrite(TRANSISTOR_PIN, LOW); // إيقاف الجهاز
    Serial.println("Power off due to auto-off timer.");
  }

  lastButtonState = buttonState; // حفظ حالة الزر للمرة القادمة
}