// prog-5  Ambulance (two light & buzz)

int white = 7;
int red = 8;
int buzz = 9;

void setup() {
  pinMode(white, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(white, HIGH);
  digitalWrite(buzz, HIGH);
  digitalWrite(red, LOW);
  delay(200);
  
  digitalWrite(red, HIGH);
  digitalWrite(white, LOW);
  digitalWrite(buzz, LOW);
  delay(200);
}
