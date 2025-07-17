#define TRIG_PIN 9
#define ECHO_PIN 10
#define TEMP_PIN A0  // الطرف الموصل بـ TMP36

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TEMP_PIN, INPUT);  // قراءة من TMP36
  Serial.begin(9600); // لعرض النتائج في السيريال
}

void loop() {
  // قراءة المسافة من حساس الترا سونيك
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = (duration / 2) * 0.0343;  // حساب المسافة بالسنتيمتر
  
  // قراءة درجة الحرارة من TMP36
  int tempValue = analogRead(TEMP_PIN); // قراءة قيمة TMP36
  float voltage = (tempValue / 1024.0) * 5.0; // تحويل إلى فولت
  float temperatureC = (voltage - 0.5) * 100; // تحويل الفولت إلى درجة مئوية

  // طباعة القيم في السيريال
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm, ");
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  delay(500); // تأخير لمدة نصف ثانية
}