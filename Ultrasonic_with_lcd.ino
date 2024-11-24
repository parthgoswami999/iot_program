#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
const int trig = 10;
const int echo = 11;
long duration, inches, cm;
void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  duration = pulseIn(echo, HIGH);

  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  // Serial.print(inches);
  // Serial.print("in, ");
  // Serial.print(cm);
  // Serial.print("cm");
  // Serial.println();

  lcd.setCursor(0, 0);
  lcd.print("Distance:- ");
  lcd.print(cm);
  Serial.print(cm);
  Serial.print("cm, ");
  lcd.print(" CM");
  delay(10);

  lcd.setCursor(0, 1);
  lcd.print("Distance:- ");
  lcd.print(inches);
  Serial.print(inches);
  Serial.print("inch");
  lcd.print("in");
  delay(10);
  Serial.println();
  delay(500);
}

long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are 73.746
  // microseconds per inch (i.e. sound travels at 1130 feet per second).
  // This gives the distance travelled by the ping, outbound and return,
  // so we divide by 2 to get the distance of the obstacle.
  // See: https://www.parallax.com/package/ping-ultrasonic-distance-sensor-downloads/
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
