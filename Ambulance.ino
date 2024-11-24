// AMBULANCE program

int white = 7;
int red = 8;

void setup() {
  // put your setup code here, to run once:

  pinMode(white, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(white, HIGH);
  digitalWrite(red, LOW);
  delay(500);
  
  digitalWrite(red, HIGH);
  digitalWrite(white, LOW);
  delay(500);
}
