#define EN  5 // Enable pin
#define FWD 4 // Pin til det fremadg?ende signal
#define BCK 3 // Pin til det bagudg?ende

#define BTN 8 // Knappens pin
#define AIN A0 // Analog input

#define FORWARD 1
#define BACK 0

boolean direction = 1;
int speed = 0;
int turnMotor (boolean dir, int spd); // Vores egen funktion deklareres.

unsigned long timer = 0;

void setup() {
	// BTN er input.
	pinMode(BTN, INPUT);
	
  // Alle pins s�ttes til output:
  pinMode(FWD, OUTPUT);
  pinMode(BCK, OUTPUT);
  pinMode(EN, OUTPUT);

	// Set timer:
	timer = millis();
}

void loop() {

	if(digitalRead(BTN) == HIGH && (millis() > timer + 200)){
    timer = millis();
		direction = !direction;
	}

	speed = analogRead(AIN)/4;
	
	turnMotor(direction,speed);

}


// Definitionen p? vores egen funktion:
int turnMotor (boolean dir, int spd){ // Tager to argumenter: dit og spd.
  switch (dir){ // Afh�ngig af retning, s�ttes FWD og BCK forskelligt.
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

