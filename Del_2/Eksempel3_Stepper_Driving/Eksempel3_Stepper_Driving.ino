#include <CheapStepper.h>

#define IN1 11
#define IN2 10
#define IN3 9
#define IN4 8

CheapStepper stepper(IN1, IN2, IN3, IN4);

boolean moveClockwise = true;

void setup() {
  Serial.begin(9600);
  Serial.println("Ready to start moving!");
}

void loop() {
  
  //Der er 4096 Steps i en fuld rotation af vores stepper.
  for (int s=0; s<4096; s++){
    stepper.step(moveClockwise); //.step stepper med eller mod uret, afhængigt af en bool true for CW og vice versa
                                  //Ellers kan man også bruge stepper.stepCW(); or stepper.stepCCW();

    int nStep = stepper.getStep(); //Vi får positionen vha. .getStep()

    //Hvert 64ne step, printes positionen:
    if (nStep % 64 == 0){
      Serial.print("current step position: "); Serial.print(nStep);
      Serial.println();
    }
  }
  
  delay(1000);
  moveClockwise = !moveClockwise;
}
