const int ledPin = 13; // ledPin sættes op til at holde "adressen" på pin 13.
const int buttonPin = 12; // buttonPin sættes op til at holde "adressen" på pin 12.

// Boolske værdier er enten sande eller falske.
bool ledState = false; // En variabel ledState initialiseres som en Boolsk false.

void setup() {
  pinMode(ledPin, OUTPUT); // LED'ens I/O pin sættes op som output.
  pinMode(buttonPin, INPUT); // Knappens'ens I/O pin sættes op som input.
}

void loop() {
  if (digitalRead(buttonPin) == HIGH){ // Hvis buttonPin er lig med Høj/1/sand/tændt:
    
    // !-Operatoren bruges til at få det omvendte.
    ledState = !ledState; // Så ledState skifter til den modsatte værdi.
    digitalWrite(ledPin, ledState); //Så sættes ledPin til ledStates værdi.
    
    //delay()-funktionen venter i det antal millisekunder, den modtager.
    delay(200); // Der ventes 200 millisekunder for at undgå mekanisk prel.
  }
}
