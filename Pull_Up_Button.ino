// Prog-7 (PULL UP BUTTON)

int light = 8;
int pull_up = 12;

void setup() {

  pinMode(light, OUTPUT);
  pinMode(pull_up, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  int val = digitalRead(pull_up);

  Serial.print("Button:- ");
  Serial.println(val);

  if(val == 0) {
    digitalWrite(light, HIGH);
  }
  else {
    digitalWrite(light, LOW);
  }
  Serial.println(val);
}