void setup()
{
  bool e = true;
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  unsigned long previousMillis;
  unsigned long currentMillis = millis();
  if (currentMillis-previousMillis>=10000){
  previousMillis=currentMillis;
  int i = analogRead(A0);

    if (i<=950 && i>=100 && e==true){
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      Serial.println("Luz ambiente");
      Serial.println(i);
      e=false;
    }
    if (i<=1023 && i>=950 && e==false){
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      Serial.println("Luz minima");
      Serial.println(i);
      e=true;
    }
    if (i<=70 && i>=0 && e==false){
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      Serial.println("Luz maxima");
      Serial.println(i);
      e=true;
    }
    }
}