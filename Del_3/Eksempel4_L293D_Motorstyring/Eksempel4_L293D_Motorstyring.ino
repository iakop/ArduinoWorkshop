#define EN  5 // Enable pin
#define FWD 4 // Pin til det fremadgående signal
#define BCK 3 // Pin til det bagudgående

enum direction {FORWARD, BACK}; // En enumerering af to tilstande, frem og tilbage.
int turnMotor (direction dir, int spd); // Vores egen funktion deklareres.

void setup() {
  // Alle pins sættes til output:
  pinMode(FWD, OUTPUT);
  pinMode(BCK, OUTPUT);
  pinMode(EN, OUTPUT);
}

void loop() {
  // For en mængde tid kører motorerne frem, med trinvis acceleration.
  for (float i = 0; i <= 255; i += 255/5){
    turnMotor(FORWARD, (int)i);
    delay(1000);
  }
  // Og så vender de igen.
  for (float i = 0; i <= 255; i += 255/5){
    turnMotor(BACK, (int)i);
    delay(1000);
  }
}


// Definitionen på vores egen funktion:
int turnMotor (direction dir, int spd){ // Tager to argumenter: dit og spd.
  switch (dir){ // Afhængig af retning, sættes FWD og BCK forskelligt.
    case FORWARD:
      digitalWrite(BCK, LOW);
      digitalWrite(FWD, HIGH);
      analogWrite(EN, spd);
      break;
    case BACK:
      digitalWrite(FWD, LOW);
      digitalWrite(BCK, HIGH);
      analogWrite(EN, spd);
      break;
    default:
      digitalWrite(FWD, LOW);
      digitalWrite(BCK, LOW);
      analogWrite(EN, 0);
      return -1;
      break;
  }
  return 0;
}

