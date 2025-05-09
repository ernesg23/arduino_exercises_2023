int i=0;
int tiempo=800;
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(i);
    if(digitalRead(5)){
    if(i == 100){
     digitalWrite(3, HIGH);
     delay(tiempo);
    }
    if(i < 100){
     digitalWrite(4, HIGH);
     delay(tiempo);
    }
    if(i > 100){
     digitalWrite(2, HIGH);
     delay(tiempo);
    }
  }
  else
  {
    i= i+20;
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  if(digitalRead(6)){
    Serial.println("Reset");
     i=0;
    }
  delay(tiempo);
}
/*
 Hecho por Ernesto Gallego de 3°5
 24/04/2023
 Variables usadas: i
 Pines de salida usados: 2, 3, 4
 Pines de entrada usados: 5, 6
*/