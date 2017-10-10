#define CLOCKPIN 7
#define LATCHPIN 6
#define DATAPIN 5

#define BTNPIN 4

int count = 0;
long int wait = 0;

/*
int ssegArray[10] = {B11111100,
                    B01100000,
                    B11011010,
                    B11110010,
                    B01100110,
                    B10110110,
                    B10111110,
                    B11100000,
                    B11111110,
                    B11100110};
*/

int ssegArray[10] = {252,
                    96,
                    218,
                    242,
                    102,
                    182,
                    190,
                    224,
                    254,
                    230};

void setup() {
  pinMode(BTNPIN, INPUT);
  pinMode(CLOCKPIN, OUTPUT);
  pinMode(LATCHPIN, OUTPUT);
  pinMode(DATAPIN, OUTPUT);
  wait = millis();
  digitalWrite(LATCHPIN, LOW);
  shiftOut(DATAPIN, CLOCKPIN, LSBFIRST, ssegArray[count]);
  digitalWrite(LATCHPIN, HIGH);
}

void loop() {
  if((digitalRead(BTNPIN) == HIGH) && (millis() >= wait+200)){
    wait = millis();
    count++;
    if(count >= 10){
      count = 0;
    }
    digitalWrite(LATCHPIN, LOW);
    shiftOut(DATAPIN, CLOCKPIN, LSBFIRST, ssegArray[count]);
    digitalWrite(LATCHPIN, HIGH);
  }
}
