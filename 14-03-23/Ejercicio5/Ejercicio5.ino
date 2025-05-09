int tiempoE=2000;
int tiempoF=(-200);
void setup() {
pinMode(5,OUTPUT);
pinMode(3,OUTPUT);
Serial.begin(9600);
}

void loop() {
Serial.println(tiempoE);
digitalWrite(5,HIGH);
digitalWrite(3,HIGH);
delay(tiempoE);
digitalWrite(5,LOW);
digitalWrite(3,LOW);
delay(tiempoE);
tiempoE = tiempoE + tiempoF;
if (tiempo==2000){
  tiempoF = (-200)
}
if (tiempoE==0){
  tiempoF = 200;
};
}