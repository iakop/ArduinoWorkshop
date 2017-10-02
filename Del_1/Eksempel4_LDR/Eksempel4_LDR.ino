#define LEDPIN 6 // Konstanten LEDPIN er sat til 6 for PWM.

int ldrVal = 0; // En variabel integer sættes op til at holde LDR'ens værdi.
int pwmOut = 0; // En variabel integer sættes op til at holde PWM output argumentet.

void setup() {
  pinMode(LEDPIN, OUTPUT); //ledPin sættes som output.
  Serial.begin(9600); //Den serielle kommunikation mellem Arduino og Computer påbegyndes med en baudrate på 9600 baud (tegn/s)
}

void loop() {
  ldrVal = analogRead(A0); // Der foretages en analoglæsning på A0.
  Serial.print("ldrVal = "); // Værdien for aflæsningen skrives til det serielle vindue.
  Serial.println(ldrVal); // Værdien for aflæsningen skrives til det serielle vindue.

  pwmOut = map(ldrVal,1023,344,0,255); // pwmOut får værdien fra ldrVal, Det mappes inverst, ud fra LDR'ens konfiguration. Så en høj spænding giver lidt lys.
  analogWrite(LEDPIN, pwmOut); // LEDPIN genererer et PWM signel, der svarer til den dutycycle tallet fra 0-255 repræsenterer.
  Serial.println(pwmOut); 
  Serial.print("Dutycycle = "); // Dutycycle skal også leveres til Serial vinduet.
  Serial.print((float)pwmOut/255.0*100.0); // Det beregnes som en normal procentomregning udfra 255 som maksværdien.
  Serial.println("%"); // Et procenttegn på til sidst, for at gøre det pænt.
}
