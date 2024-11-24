int pull_up = 8;
int red = 9;
int green = 10;
int buzz = 11;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pull_up, INPUT_PULLUP);
  pinMode(red, OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(buzz, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sv = digitalRead(pull_up);
  Serial.println(sv);
  if(sv == HIGH){
    delay(1000);
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(buzz,HIGH);
    delay(1000);
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    digitalWrite(buzz,LOW);
  }else{
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    digitalWrite(buzz,LOW);
  }
}
