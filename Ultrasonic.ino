#include <LiquidCrystal.h>
int trig=11;
int echo=10;
int red=8;
int green=9;
long duration, cmDuration, inchDuration;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  // put your setup code here, to run once:
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  duration = pulseIn(echo,HIGH);
  cmDuration = duration * 0.0343 / 2;
  inchDuration = cmDuration / 2.54;
  Serial.print("Cm:- ");
  Serial.println(cmDuration);
  Serial.print("Inch:- ");
  Serial.println(inchDuration);

  if(cmDuration < 10){
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
  }else if(cmDuration > 10 && cmDuration < 20){
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
  }else{
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("CM:- ");
  lcd.print(cmDuration);

  lcd.setCursor(0, 1);
  lcd.print("Inch:- ");
  lcd.print(inchDuration);

  delay(500);
}