#include <FrequencyTimer2.h>
#include "Opgave3_LED_Matrix_Chars.h"

byte leds[8][8]; // En matrix for led'ernes udgangsværdier sættes op.

int pins[17]= {-1, 5, 4, 3, 2, 14, 15, 16, 17, 13, 12, 11, 10, 9, 8, 7, 6}; // En liste over udgangspin sættes op.

int cols[8] = {pins[13], pins[3], pins[4], pins[10], pins[06], pins[11], pins[15], pins[16]}; // 
int rows[8] = {pins[9], pins[14], pins[8], pins[12], pins[1], pins[7], pins[2], pins[5]};

const int numPatterns = 11;
byte patterns[numPatterns][8][8] = {
  H,E,L,L,O,SPACE
};

int pattern = 0;

void setup() {
  // sets the pins as output
  for (int i = 1; i <= 16; i++) {
    pinMode(pins[i], OUTPUT);
  }

  // set up cols and rows
  for (int i = 1; i <= 8; i++) {
    digitalWrite(cols[i - 1], LOW);
  }

  for (int i = 1; i <= 8; i++) {
    digitalWrite(rows[i - 1], LOW);
  }
  freqTimerInit();
  clearLeds();
  setPattern(pattern);
}

void loop() {
    pattern = ++pattern % numPatterns;
    slidePattern(pattern, 60);
}
