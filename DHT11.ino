#include <DHT.h>
#include <LiquidCrystal.h>
#define DHTTYPE DHT11
int dht_pin = 13;

DHT dht(dht_pin, DHTTYPE);
LiquidCrystal lcd(2,3,4,5,6,7);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);
}

void loop() {
  delay(2000);

  float t = dht.readTemperature();
  float h = dht.readHumidity(); 
  float f = dht.readTemperature(true);

  if (isnan(t) || isnan(h) || isnan(f)) {
    Serial.println("DHT11 sernsor failed to detecting...");
  }

  Serial.println("------------------------------------------");
  Serial.println((String) "Temprature: " + t + " °C \t " + f + " °F");
  Serial.println((String) "Humidity: " + h + " %");
  lcd.clear();

  // Serial.print("Tem: -");
  // Serial.print(t);
  // Serial.print("Humidity: -");
  // Serial.print(h);
  // Serial.print("F: -");
  // Serial.print(f);
  // Serial.println();


  lcd.setCursor(0, 0);
  lcd.print("Tem:- ");
  lcd.println(t);
  delay(10);
  
  lcd.setCursor(0, 1);
  lcd.print("Hum:- ");
  lcd.println(h);
  delay(10);

}
