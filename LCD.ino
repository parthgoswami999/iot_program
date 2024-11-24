#include <LiquidCrystal.h>
#include <DHT.h>

int rs = 0;
int en = 1;

int d4 = 2;
int d5 = 3;
int d6 = 4;
int d7 = 5;

int dht_pin = 6;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
DHT dht(dht_pin, DHT11);

int arr[7] = { 7, 8, 9, 10, 11, 12, 13 };

int sarr[10][7] = {
  { 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 1, 1, 1, 1 },
  { 0, 0, 1, 0, 0, 1, 0 },
  { 0, 0, 0, 0, 1, 1, 0 },
  { 1, 0, 0, 1, 1, 0, 0 },
  { 0, 1, 0, 0, 1, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 1, 1 },
  { 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0 }
};



void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(arr[i], OUTPUT);
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 7; j++) {
      digitalWrite(arr[j], sarr[i][j]);
    }
    delay(1000);
  }

  float sumTemp = 0.0;
  float sumHumi = 0.0;
  dht.begin();
  lcd.begin(16, 2);
  Serial.begin(9600);
  delay(1000);

  for (int i = 0; i < 5; i++) {
    delay(1000);
    float t = dht.readTemperature();
    float h = dht.readHumidity();
    if (isnan(t) || isnan(h)) {
      lcd.print("not detected");
    }

    Serial.print(t);
    sumTemp += t;
    sumHumi += h;
    delay(1000);
  }

  float avgTemp = sumTemp / 5;
  float avgHumi = sumHumi / 5;
  
  lcd.setCursor(0, 0);
  lcd.print((String) "T-A: " + avgTemp);
  lcd.setCursor(0, 1);
  lcd.print((String) "H-A: " + avgHumi);
}


void loop() {
}
