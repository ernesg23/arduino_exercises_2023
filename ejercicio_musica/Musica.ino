#define TRIGGER 5
#define ECHO 18
#define BEE 19

int notes[24] = {261, 277, 294, 311, 330, 349, 369, 392, 415, 440, 466, 494, 523, 554, 587, 622, 659, 698, 740, 784, 831, 880, 932, 988};
//int letters_notes[c, c#, d, d#, e, f, f#, g, g#, a, a#, b, b#]

void setup() {
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BEE, OUTPUT);
}

void loop() {
  for(int i=0; i<24; i++){
 tone(BEE, notes[i]);
 delay(2000);
 noTone(BEE);
 delay(2000);
}
}
