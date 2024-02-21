#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int sensor = A1;
const int Buz = 8;
const int ignition = 10;
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(sensor, INPUT);
  pinMode(Buz, OUTPUT);
  pinMode(ignition, OUTPUT);
}

void loop() {
  int val = analogRead(sensor);
  int val2 = (val ) * (5.0 / 1024.0)+60;
  float mgl = 0.67 * val2;
  Serial.print("Alcohol ");
  Serial.print(mgl);
  Serial.println(" mg/dL");
  lcd.print("READING VALUES :");
  delay(1000);
  lcd.clear();
  lcd.print("READING VALUES :");
  delay(1000);
  lcd.clear();
  lcd.print("READING VALUES :");
  delay(1000);
  lcd.clear();
  lcd.print("alcohol ");

  if (mgl > 42)
  {
    lcd.print(mgl);
    lcd.print("mg/dL");
    delay(1000);
    digitalWrite(ignition, LOW);
    digitalWrite(Buz, HIGH);
    Serial.println("Engine Failed ");
    delay(1000);
    Serial.println("Please Stop the vehicle");
    lcd.setCursor(0, 1);
    lcd.clear();
    lcd.print("Driver Drunk");
    delay(4000);
    lcd.clear();
  }
  if (mgl < 42)
  { 
    lcd.print("0 mg/dL");
    delay(1000);
    digitalWrite(ignition, HIGH);
    digitalWrite(Buz, LOW);
    Serial.println("Normal");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("Normal");
    delay(1000);
    lcd.clear();
  }
}
