int ir = 3;
int white = 7;
int red = 8;
int buzz = 9;

void setup() {
  Serial.begin(9600);
  pinMode(ir,INPUT);
  pinMode(white,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(buzz,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(ir));
  if(digitalRead(ir) == LOW){
    Serial.println("Hi");
    //digitalWrite(ir,HIGH);
    digitalWrite(white,LOW);
    digitalWrite(red,HIGH);
    digitalWrite(buzz,HIGH);
    delay(200);

    digitalWrite(white,HIGH);
    digitalWrite(red,LOW);
    digitalWrite(buzz,LOW);
    delay(200);

  }else{
    digitalWrite(white,LOW);
    digitalWrite(red,LOW);
    digitalWrite(buzz,LOW);
  }
}
