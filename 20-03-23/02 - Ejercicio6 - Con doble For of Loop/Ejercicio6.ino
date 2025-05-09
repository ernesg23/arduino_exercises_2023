int tiempoE;
void setup() {
pinMode(5,OUTPUT);
pinMode(3,OUTPUT);
}
//For of loop se usa para ciclar una determinada cantidad de veces un pedazo de código
void loop() {
tiempoE=2000;
for (int i=0; i<2; i++){
 for (int i=0; i<5; i++){
   digitalWrite(5,HIGH);
   digitalWrite(3,HIGH);
   delay(tiempoE);
   digitalWrite(5,LOW);
   digitalWrite(3,LOW);
   delay(tiempoE);
 }
 tiempoE=600;
}
}

