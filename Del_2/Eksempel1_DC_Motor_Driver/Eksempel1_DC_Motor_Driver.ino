#define MOTORPIN 5
#define AIN A0

int potRead = 0;
int motorSpeed = 0;

void setup(){
	pinMode(MOTORPIN, OUTPUT);
	Serial.begin(9600);
}

void loop(){
	potRead = analogRead(AIN);
	motorSpeed = potRead/4;
	analogWrite(MOTORPIN, motorSpeed);
	Serial.print("potRead = "); Serial.println(potRead); // potReads værdi skrives ud på den serielle forbindelse.
  Serial.print("motorSpeed = "); Serial.println(motorSpeed); // servoPos' værdi skrives ud på den serielle forbindelse.
}
