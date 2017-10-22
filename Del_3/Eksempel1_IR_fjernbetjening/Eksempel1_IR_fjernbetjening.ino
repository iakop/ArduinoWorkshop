#include <IRremote.h> // Inkluderer IRremote librariet.
#include <Servo.h> // Inkluderer Servo librariet.

#define RECV_PIN 11 // RECV_PIN er den pin vi modtager på.
#define SERVO_PIN 9 // SERVO_PIN er servoens pin.

IRrecv myRecv(RECV_PIN); // Her instantieres et objekt af typen IRrecv, som er en modtager.
decode_results results; // Et resultatobjekt instantieres ligeledes.

int evaluate(int data);

Servo myServo; // myServo instantieres.

unsigned int angle[3] = {0, 0, 0}; // Hvert ciffer for vinklen skal holdes i hvert sit array index.
unsigned int servoPos = 0; // Servoen starter i 0.
unsigned int index = 0; // index bruges til at finde rundt i angle-arrayet.
int number = -1; // Det evaluerede tal fra remote-inputtet. '-1' betyder der ikke er et gyldigt tal.
char prompt[] = "Please enter servo position on remote (000-180): "; // Her kan vores input prompt defineres.

void setup()
{
  Serial.begin(9600); // Den serielle kommunikation påbegyndes.
  myRecv.enableIRIn(); // Receiveren startes.
  myServo.attach(SERVO_PIN); // myServo attaches til SERVO_PIN.
  Serial.print(prompt); // Prompten udskrives.
  myServo.write(0); // Servoen sættes i 0.
}

void loop() {
  if (myRecv.decode(&results)) { // Hvis der fås et ordentligt resultat med decoderen.
    
    number = evaluate(results.value); // Outputtet i results.value evalueres til en talværdi, med vores egen funktion.
    
    if (number >= 0 && number <= 9){ // Hvis tallet er gyldigt.
      angle[index] = evaluate(results.value); // Så skrives det til den nuværende angle-index.
      Serial.print(angle[index]); // Og skrives ud på den serielle forbindelse.
      index++; // Gør klar til næste index.
      
      if (index > 2){ // Hvis vi er ved vejs ende.
        servoPos = angle[0]*100+angle[1]*10+angle[2]; // servoPos gives ved at konvertere cifrene til et tal.
     
        myServo.write(servoPos); // Servoen indtager positionen servoPos.
        
        index = 0; // index resettes.
        servoPos = 0; // servoPos resettes.
        
        Serial.println(); // Der foretages lige et linjeskift.
        Serial.print(prompt); // Prompten udskrives igen.
      }
    }
    myRecv.resume(); // myRecv gør sig klar til næste værdi.
  }
}

int evaluate(int data){ //Egen funktion til at håndtere remote-dataene.
  switch (data) // Der vælges en retur-værdi udfra hex-værdien modtaget.
  {
    case 0xFF6897:  
      return 0; 
      break;
    
    case 0xFF30CF:  
      return 1; 
      break;

    case 0xFF18E7:  
      return 2; 
      break;

    case 0xFF7A85:  
      return 3; 
      break;

    case 0xFF10EF:  
      return 4; 
      break;

    case 0xFF38C7:  
      return 5; 
      break;

    case 0xFF5AA5:  
      return 6; 
      break;

    case 0xFF42BD:  
      return 7; 
      break;

    case 0xFF4AB5:  
      return 8; 
      break;

    case 0xFF52AD:  
      return 9; 
      break;

    default:
      return -1; // Ved andet input, returnér -1 for fejl.
      break;
  }
  return -1; // Hvis alt fejler, returnér -1 for fejl.
}

