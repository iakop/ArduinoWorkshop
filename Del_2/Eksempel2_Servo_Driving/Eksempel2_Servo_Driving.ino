#include <Servo.h> // Her inkluderes Servo biblioteket.

#define SERVPIN 9 // Servopinnen defineres til at være pin 9
#define AIN A0 // Pinnen til analog læsning bliver defineret.

Servo myServo; // Et servo-objekt, myServo instantieres.
int potRead = 0; // potRead initialiseres til 0.
int servoPos = 0; // Servopositionen servoPos instantieres til 0.

long unsigned timer = 0;

void setup() {
  myServo.attach(SERVPIN); // myServo sættes til på pin 9 (PWM pin).
  Serial.begin(9600); // Den serielle forbindelse påbegyndes.
}

void loop() {
  potRead = analogRead(AIN); // potentiometret aflæses til potRead.
  servoPos = map(potRead, 0, 1023, 1, 179); // potRead omregnes til en servoPos.
  myServo.write(servoPos); // servoPos (i grader) skrives til myServo.

  if(timer <= millis() - 1000){
    Serial.print("potRead = "); Serial.println(potRead); // potReads værdi skrives ud på den serielle forbindelse.
    Serial.print("servoPos = "); Serial.println(servoPos); // servoPos' værdi skrives ud på den serielle forbindelse.
    timer = millis();
  }
  
}