#define LEDPIN 6 // Konstanten LEDPIN er sat til 6, denne gang kræves en ekstern LED.
#define ANALOGIN A0

int potVal = 0; // En variabel integer sættes op til at holde potentiometerværdien.
int pwmOut = 0; // En variabel integer sættes op til at holde PWM output argumentet.

void setup() {
  pinMode(LEDPIN, OUTPUT); //ledPin sættes som output.
  Serial.begin(9600); //Den serielle kommunikation mellem Arduino og Computer påbegyndes med en baudrate på 9600 baud (tegn/s)
}

void loop() {
  potVal = analogRead(A0); // Der foretages en analoglæsning på A0.
  Serial.print("potVal = "); // Værdien for aflæsningen skrives til det serielle vindue.
  Serial.println(potVal); // Værdien for aflæsningen skrives til det serielle vindue.

  pwmOut = potVal/4; // pwmOut får værdien fra potVal, op til 1023/4 hvilket højst giver 255, som er maks input til analogWrite.
  analogWrite(LEDPIN, pwmOut); // LEDPIN genererer et PWM signel, der svarer til den dutycycle tallet fra 0-255 repræsenterer.
  Serial.print("Dutycycle = "); // Dutycycle skal også leveres til Serial vinduet.
  Serial.print((float)pwmOut/255.0*100.0); // Det beregnes som en normal procentomregning udfra 255 som maksværdien.
  Serial.println("%"); // Et procenttegn på til sidst, for at gøre det pænt.
}
