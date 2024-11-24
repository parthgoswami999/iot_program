#include <LiquidCrystal.h>
//LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
LiquidCrystal lcd(2,3,4,5,6,7);
void setup() {
  lcd.begin(16, 2);
  lcd.print("Hello Good");
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  lcd.setCursor(1, 1);
  lcd.print("Hello");
  Serial.println("Hello");

  lcd.setCursor(0, 1);
  lcd.print("Good");
  Serial.print("Good");
  lcd.clear();
}
