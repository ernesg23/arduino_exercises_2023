int i=1;
int e=1;
int q=HIGH;
int r=1000
void setup()
{
  pinMode(13,OUTPUT)
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}
void loop(){
  Serial.println(i);
  if(i>12){
    e=(-1);
    q=LOW;
    r= r-200;
  };
  if(i<2){
    e=1;
    q=HIGH;
    r= r-200;
  };
  i= i+e;
  digitalWrite(i,q);
  delay(r);
  if(r==0){
   r=1000;
 };
}
/*
Hecho por: Ernesto Gallego de 3°5
Fecha: 10/04/2023
Pines usados: Pin 2, Pin 3, Pin 4, Pin 5, Pin 6, Pin 7, Pin 8, Pin 9, Pin 10, Pin 11, Pin 12, Pin 13 
Variables usadas: i, e, q, r
*/