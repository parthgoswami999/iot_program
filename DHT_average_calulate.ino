#include <DHT.h>
#include <LiquidCrystal.h>
#define DHTTYPE DHT11
int dht_pin = 13;
int red = 8;
int yellow = 9;
int ir = 10;
int pull = 12;

DHT dht(dht_pin, DHTTYPE);
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(ir, INPUT);
  pinMode(pull, INPUT_PULLUP);
}

void loop() {
  int val = digitalRead(pull);
  if (val == 0) {
    Serial.println("Button is On");

    if (digitalRead(ir) == LOW) {
      float totalTemperatureC = 0;
      float totalTemperatureF = 0;
      float totalHumidity = 0;
      int countReading = 0;

      for (int i = 0; i < 15; i++) {
        float t = dht.readTemperature();
        float h = dht.readHumidity();
        float f = dht.readTemperature(true);
        Serial.print("");
        Serial.print(t);
        Serial.println();

        if (!isnan(t) && !isnan(h) && !isnan(f)) {
          totalTemperatureC += t;
          totalTemperatureF += f;
          totalHumidity += h;
          countReading++;
        }

        delay(200);  // Short delay between readings
      }

      // Calculate the averages
      float avgTemperatureC = countReading > 0 ? totalTemperatureC / countReading : 0;
      float avgTemperatureF = countReading > 0 ? totalTemperatureF / countReading : 0;
      float avgHumidity = countReading > 0 ? totalHumidity / countReading : 0;

      // Display results
      Serial.println("------------------------------------------");
      Serial.println((String) "Avg Temperature: " + avgTemperatureC + " °C \t " + avgTemperatureF + " °F");
      Serial.println((String) "Avg Humidity: " + avgHumidity + " %");

      if (avgTemperatureC > 29) {
        digitalWrite(red, HIGH);
        digitalWrite(yellow, LOW);
      } else {
        digitalWrite(yellow, HIGH);
        digitalWrite(red, LOW);
      }

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Avg Temp: ");
      lcd.print(avgTemperatureC);
      lcd.print("C");

      lcd.setCursor(0, 1);
      lcd.print("Avg Hum: ");
      lcd.print(avgHumidity);
      lcd.print("%");

    } else {
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(ir, LOW);
    }

    delay(3000);  // Delay before the next set of readings
  } else {
    Serial.println("Button is off");
    digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(ir, LOW);
  }
}
