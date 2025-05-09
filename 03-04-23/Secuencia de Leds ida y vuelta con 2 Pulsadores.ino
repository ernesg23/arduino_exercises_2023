// C++ code
//
int i=1;
void setup()
{
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
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  Serial.begin(9600);
}
void loop(){
  Serial.println(i);
  if(digitalRead(12)){
    i++;
    int e= i-1;
    if(i>11){
      i=2;
    };
    digitalWrite(e,LOW);
    digitalWrite(i,HIGH);
    delay(600);
    digitalWrite(i,LOW);
    delay(50);
      }
  if(digitalRead(13)){
    i--;
    int q= i+1;
    if(i<2){
      i=11;
    };
    digitalWrite(q,LOW);
    digitalWrite(i,HIGH);
    delay(600);
    digitalWrite(i,LOW);
    delay(50);
  }
}
  
