// SIMPLE LINE AND BUZZ (On/Off)

int light = 8;
int buzz = 7;

void setup() {
  pinMode(light, OUTPUT);
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(light, HIGH);
  digitalWrite(buzz, HIGH);
  delay(200);

  digitalWrite(light, LOW);
  digitalWrite(buzz, LOW);
  delay(200);
}
