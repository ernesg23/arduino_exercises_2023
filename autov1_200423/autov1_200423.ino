/*
Descripcion de pines
RIGHT LEFT UP DOWN pulsadores de la palanca

Este programa identifica y hace funcionar las ruedas en las direcciones: izquierda, derecha, adelante, atrás,
arriba y derecha, arriba e izquierda, abajo y derecha, y abajo e izquierda.
Martes 18/4/2023
Comentarios:
-La rueda derecha frena mucho mejor que la rueda izquierda.
*/
#include "BluetoothSerial.h"

#define RWPMLEFT 14 //Blanco
#define LWPMLEFT 27  //violeta
#define RWPMRIGHT 13  // Amarillo
#define LWPMRIGHT 12   //Verde
#define LEFTEN 22  // Blanco
#define RIGHTEN 23  //Naranja
//Palanca
#define RIGHT 25 //Negro
#define LEFT 33 //Verde
#define DOWN 32 //Blanco
#define UP 26  // amarillo

#define VELOCIDADUP 18
#define VELOCIDADDOWN 19 

#define TRIGGER 5
#define ECHO 17

BluetoothSerial SerialBT;

float dist=0;
int rebote=50;
int stop=600;
int velocidad=250;
char direccion[5];
char palancaprev[5];
unsigned long int millis_ultimo_mensaje_bluetooth;

unsigned long previousMillis;
unsigned long period = 1000;

void prueba_motor(void);

void setup() {
 pinMode(RWPMLEFT, OUTPUT);//salidas
 pinMode(LWPMLEFT, OUTPUT);
 pinMode(RWPMRIGHT, OUTPUT);
 pinMode(LWPMRIGHT, OUTPUT);
 pinMode(LEFTEN, OUTPUT);
 pinMode(RIGHTEN, OUTPUT);
 pinMode(RIGHT, INPUT_PULLUP);  //Entradas
 pinMode(LEFT, INPUT_PULLUP);
 pinMode(DOWN, INPUT_PULLUP);
 pinMode(UP, INPUT_PULLUP);
 pinMode(VELOCIDADUP,INPUT_PULLUP);
 pinMode(VELOCIDADDOWN,INPUT_PULLUP);
 pinMode(ECHO, OUTPUT);
 pinMode(TRIGGER, INPUT);
 Serial.begin(115200);
 SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  analogWrite(LEFTEN, 0);
  digitalWrite(RWPMLEFT, LOW);
  digitalWrite(LWPMLEFT, LOW);
  analogWrite(RIGHTEN, 0);
  digitalWrite(RWPMRIGHT, LOW);
  digitalWrite(LWPMRIGHT, LOW);
  Serial.println("INICIANDO PRUEBA ");
 //prueba_motor();  
 digitalWrite(4,LOW);
}

/* //ya que es una sola linea decidi copiarla y listo
void readline(char *buf, int count){
  return Serial.readBytesUntil('\n', result, count);
}*/
float distancia;
void loop() {
unsigned long currentMillis = millis(); // guardo el tiempo actual
  if (currentMillis - previousMillis >= period) 
  { // checkea si pasaron 1000ms
    previousMillis = currentMillis;   // save the last time you blinked the LED
    //SerialBT.write(itoa(cont, buffer, 10));  
    
  }
  

  if (SerialBT.available()) {
    //Serial.write(SerialBT.read());
    char result[5] = {0}; 
    SerialBT.readBytesUntil('\n', result, 5);
    result[4]='\0';
    //distancia = medir_distancia();
    if(result[0]=='v')
    {
       Serial.print("velocidad ");
        char nro_vec[3];
      nro_vec[0]=result[1];
      nro_vec[1]=result[2];
      nro_vec[2]=result[3];
      int nro_vel = atoi(nro_vec);
      velocidad = nro_vel;
      //Serial.print("s");
      //Serial.println(dist);
      /*
      -Idea: Crear un vector y guardar en cada posición la velocidad respectiva según el orden de posición;
      luego convertir las posiciones con los valores guardados en un número el cual representará la velocidad.
      */
    }

    strncpy(direccion, result, 5);
    millis_ultimo_mensaje_bluetooth=millis();
    Serial.print("Direccion Bluetooth ");
    Serial.println(direccion);
    //direccion=result;
  } else if (millis()-millis_ultimo_mensaje_bluetooth > 300) {
    strncpy(direccion, "0000", 5);
  }

  char palancaActual[5]="0000";
  if (digitalRead(UP)==LOW){
    palancaActual[0]='u';
    palancaActual[1]='p';
  }
  if (digitalRead(DOWN)==LOW){
    palancaActual[0]='d';
    palancaActual[1]='n';
  }
  if (digitalRead(LEFT)==LOW){
    palancaActual[2]='l';
    palancaActual[3]='f';
  }
  if (digitalRead(RIGHT)==LOW){
    palancaActual[2]='r';
    palancaActual[3]='t';
  }

  if (strcmp(palancaActual, "0000") != 0)  { // Si la palanca no es cero toma prioridad
    strncpy(direccion, palancaActual, 5);
    strncpy(palancaprev, palancaActual, 5);
    velocidad=250;

  } else if (strcmp(palancaprev, "0000") != 0) { // Si la palanca si es cero declara la direccion como 0 SOLO una vez, y luego no la modifica
    strncpy(direccion, "0000", 5);
    strncpy(palancaprev, "0000", 5);
  }


  if (strcmp("up00", direccion) == 0)  {
                SerialBT.println("pepe");
                mover_adelante(velocidad);
                //Serial.println("ARRIBA");
  }

  else if (strcmp("uprt", direccion) == 0)  {
                SerialBT.println(direccion);
                mover_derecha_adelante(velocidad);
                //Serial.println("ARRIBA DERECHA");
        }

  else if (strcmp("uplf", direccion) == 0)  {
                mover_izquierda_adelante(velocidad);
                //Serial.println("ARRIBA IZQUIERDA");
        }

  else if (strcmp("dn00", direccion) == 0)  {
                mover_atras(velocidad);
                //Serial.println("ABAJO");
          }  

  else if (strcmp("dnrt", direccion) == 0)  {
                mover_derecha_atras(velocidad);
                //Serial.println("ABAJO DERECHA");
          }

  else if (strcmp("dnlf", direccion) == 0)  {
                mover_izquierda_atras(velocidad);
                //Serial.println("ABAJO IZQUIERDA");
  }

  else if (strcmp("00rt", direccion) == 0)  {
                mover_derecha(velocidad);
                //Serial.println("DERECHA");
  }

  else if (strcmp("00lf", direccion) == 0)  {
                mover_izquierda(velocidad);
                //Serial.println("IZQUIERDA");
        }
  
  else if (strcmp("0000", direccion) == 0)  {
          parar_sin_palanca();
          //Serial.println("QUIETO");
  }
  
  else if (strcmp("v", direccion) == 0)  {
          // Falta implementar
          //Serial.println("CAMBIO VELOCIDAD");
  }

}

void mover_adelante(byte velocidad)
{
Serial.println("Rueda izquierda y derecha hacia adelante");

  analogWrite(LEFTEN, velocidad);
  digitalWrite(RWPMLEFT, HIGH);
  digitalWrite(LWPMLEFT, LOW);
  analogWrite(RIGHTEN, velocidad);
  digitalWrite(RWPMRIGHT, HIGH);
  digitalWrite(LWPMRIGHT, LOW);
}

void mover_atras(byte velocidad){
Serial.println("Rueda izquierda y derecha hacia atrás");

  analogWrite(LEFTEN, velocidad);
  digitalWrite(RWPMLEFT, LOW);
  digitalWrite(LWPMLEFT, HIGH);
  analogWrite(RIGHTEN, velocidad);
  digitalWrite(RWPMRIGHT, LOW);
  digitalWrite(LWPMRIGHT, HIGH);
}

void mover_izquierda(byte velocidad){
  Serial.println("Dirección izquierda");

  analogWrite(LEFTEN, velocidad);
  digitalWrite(RWPMLEFT, LOW);
  digitalWrite(LWPMLEFT, HIGH);
  analogWrite(RIGHTEN, velocidad);
  digitalWrite(RWPMRIGHT, HIGH);
  digitalWrite(LWPMRIGHT, LOW);
}

void mover_derecha(byte velocidad){
  Serial.println("Dirección derecha");

  analogWrite(LEFTEN, velocidad);
  digitalWrite(RWPMLEFT, HIGH);
  digitalWrite(LWPMLEFT, LOW);
  analogWrite(RIGHTEN, velocidad);
  digitalWrite(RWPMRIGHT, LOW);
  digitalWrite(LWPMRIGHT, HIGH);
}

void mover_izquierda_adelante(byte velocidad){
  Serial.println("Dirección izquierda para adelante");

  analogWrite(LEFTEN, velocidad);
  digitalWrite(RWPMLEFT, LOW);
  digitalWrite(LWPMLEFT, LOW);
  analogWrite(RIGHTEN, velocidad);
  digitalWrite(RWPMRIGHT, HIGH);
  digitalWrite(LWPMRIGHT, LOW);
}

void mover_derecha_adelante(byte velocidad){
  Serial.println("Dirección derecha para adleante");

  analogWrite(LEFTEN, velocidad);
  digitalWrite(RWPMLEFT, HIGH);
  digitalWrite(LWPMLEFT, LOW);
  analogWrite(RIGHTEN, velocidad);
  digitalWrite(RWPMRIGHT, LOW);
  digitalWrite(LWPMRIGHT, LOW);
}

void mover_izquierda_atras(byte velocidad){
  Serial.println("Dirección izquierda para atrás");

  analogWrite(LEFTEN, velocidad);
  digitalWrite(RWPMLEFT, LOW);
  digitalWrite(LWPMLEFT, HIGH);
  analogWrite(RIGHTEN, velocidad);
  digitalWrite(RWPMRIGHT, LOW);
  digitalWrite(LWPMRIGHT, HIGH);
}

void mover_derecha_atras(byte velocidad){
  Serial.println("Dirección derecha para atrás");

  analogWrite(LEFTEN, velocidad);
  digitalWrite(RWPMLEFT, LOW);
  digitalWrite(LWPMLEFT, HIGH);
  analogWrite(RIGHTEN, velocidad);
  digitalWrite(RWPMRIGHT, LOW);
  digitalWrite(LWPMRIGHT, HIGH);
}

void prueba_motor(void)
{
  Serial.println("Probando Motor.....");

  analogWrite(LEFTEN, 0);
  digitalWrite(RWPMLEFT, LOW);
  digitalWrite(LWPMLEFT, LOW);
  analogWrite(RIGHTEN, 0);
  digitalWrite(RWPMRIGHT, LOW);
  digitalWrite(LWPMRIGHT, LOW);
 delay(1500);

 Serial.println("Rueda izquierda y derecha hacia adelante");

 analogWrite(LEFTEN, 250);
  digitalWrite(RWPMLEFT, HIGH);
  digitalWrite(LWPMLEFT, LOW);
  analogWrite(RIGHTEN, 250);
  digitalWrite(RWPMRIGHT, HIGH);
  digitalWrite(LWPMRIGHT, LOW);
 delay(10000);

  analogWrite(LEFTEN, 0);
  digitalWrite(RWPMLEFT, LOW);
  digitalWrite(LWPMLEFT, LOW);
  analogWrite(RIGHTEN, 0);
  digitalWrite(RWPMRIGHT, LOW);
  digitalWrite(LWPMRIGHT, LOW);
 delay(1500);

 Serial.println("Rueda izquierda y derecha hacia atrás");

  analogWrite(LEFTEN, 250);
 digitalWrite(RWPMLEFT, LOW);
  digitalWrite(LWPMLEFT, HIGH);
  analogWrite(RIGHTEN, 250);
  digitalWrite(RWPMRIGHT, LOW);
  digitalWrite(LWPMRIGHT, HIGH);
 delay(10000);

 analogWrite(LEFTEN, 0);
  digitalWrite(RWPMLEFT, LOW);
  digitalWrite(LWPMLEFT, LOW);
  analogWrite(RIGHTEN, 0);
  digitalWrite(RWPMRIGHT, LOW);
  digitalWrite(LWPMRIGHT, LOW);
  delay(1000);

 Serial.println("Ciclo terminado");
}
void parar_sin_palanca(void){
 analogWrite(LEFTEN, 0);
  digitalWrite(RWPMLEFT, LOW);
  digitalWrite(LWPMLEFT, LOW);
  analogWrite(RIGHTEN, 0);
  digitalWrite(RWPMRIGHT, LOW);
  digitalWrite(LWPMRIGHT, LOW);
  delay(stop);
}

void velocidad_pulsadores()
{
  if (digitalRead(VELOCIDADUP)==HIGH){    
    Serial.print(velocidad);
    velocidad ++; 
  }
  if (digitalRead(VELOCIDADDOWN)==HIGH){
    Serial.print(velocidad);
    velocidad --;
  }
}
float medir_distancia(){
  long tiempo;
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  tiempo = pulseIn (ECHO, HIGH);
  
  dist = tiempo/58;
  Serial.print("tiempo : ");
  Serial.println (tiempo);
  Serial.print("Distancia: ");
  Serial.println (dist);
  SerialBT.print(dist);
  return dist;
 }