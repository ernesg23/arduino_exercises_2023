//#include <Wire.h>
//#include <Adafruit_PWServoDriver.h>

//#define PosicionesServo 4
void setup() {
    Serial.begin (9600);
    Serial.println("Prueba valores límite");/*
    pca.begin();
    pca.setPWFreq(60);
    myservo.attach(2);

  int ValorMin[PosicionesServo] = (0, 0, 0, 0);
  int ValorMax[PosicionesServo] = (0, 0, 0, 0);
  int ValorMin[PosicionesServo] = (0, 0, 0, 0);
  int ValorMin[PosicionesServo] = (180, 180, 180, 180);
*/
  //Adafruit_PWServoDriver pca= Adafruit_PWServoDriver(0x40)
}

void loop() {
  for (int i=0; i < 2500; i+= 10){
    Serial.print("Servo valor");
    Serial.println(i);
    servo.write(i);
  }
}