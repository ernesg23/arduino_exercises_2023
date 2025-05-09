void setup() {
pinMode(5,OUTPUT);
pinMode(3,OUTPUT);
}

void loop() {
digitalWrite(5,HIGH);
digitalWrite(3,LOW);
delay(600);
digitalWrite(5,LOW);
digitalWrite(3,HIGH);
delay(600);
}