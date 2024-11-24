int ir = 8;
int buzz = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(ir, INPUT);
  pinMode(buzz, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(ir));
  if(digitalRead(ir) == LOW){
    digitalWrite(buzz, HIGH);
    Serial.println(digitalRead(ir));
    delay(0);
  }else{
    digitalWrite(buzz, LOW);
    delay(0);
  }
}
