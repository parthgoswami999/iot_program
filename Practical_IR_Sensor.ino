int buzz = 10;
int ir = 3;
int led = 8;
void setup() {
  // put your setup code here, to run once:
  pinMode(buzz, OUTPUT);
  pinMode(ir,INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(ir) == LOW){
    digitalWrite(led, HIGH);
    digitalWrite(buzz, HIGH);
    delay(0);
  }else{
    digitalWrite(led, LOW);
    digitalWrite(buzz, LOW);
    delay(0);
  }
}
