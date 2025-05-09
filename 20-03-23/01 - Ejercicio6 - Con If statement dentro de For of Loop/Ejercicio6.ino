int tiempoE=2000;
void setup() {
pinMode(5,OUTPUT);
pinMode(3,OUTPUT);
}
//For of loop se usa para ciclar una determinada cantidad de veces un pedazo de código
void loop() {
for(int i=0; i<10; i++)
{
  if (i>4) tiempoE=600;
  digitalWrite(5,HIGH);
  digitalWrite(3,HIGH);
  delay(tiempoE);
  digitalWrite(5,LOW);
  digitalWrite(3,LOW);
  delay(tiempoE);
if (i==9) tiempoE=2000;
};
}