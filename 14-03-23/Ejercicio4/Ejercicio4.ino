int tiempo=1000;

void setup() {
pinMode(5,OUTPUT);
pinMode(3,OUTPUT);
}

void loop() {
digitalWrite(5,HIGH);
digitalWrite(3,HIGH);
delay(tiempo);
digitalWrite(5,LOW);
digitalWrite(3,LOW);
delay(tiempo);
tiempo = tiempo - 200;
if (tiempo==200)(
  tiempo=1000
);
}
/*
Hecho por: Ernesto Gallego de 3°5
Fecha: 14/03/2023
Pines usados: Pin 5, Pin 3
*/