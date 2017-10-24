#include "library.h"

int a, b = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  a = random(10);
  b = random(10);
  Serial.print(a);
  Serial.print(" + ");
  Serial.print(b);
  Serial.print(" = ");
  Serial.println(add(random(10),random(10)));
}

int add(int x, int y){
  int sum = x + y;
  return sum;
}

