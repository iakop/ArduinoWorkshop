const int ledPin = 13; // Pin 13 har en debug LED forforbundet på boardet. ledPin sættes op til at holde "adressen".

void setup() {
  // Koden der skrives her, køres kun én gang!

  pinMode(ledPin, OUTPUT); // LED'ens I/O pin sættes op som output. For hardwarens skyld.

}

void loop() {
  // Koden der skrives her, gentages resten af tiden.
  
  digitalWrite(ledPin, HIGH); // LED'ens I/O Pin Gøres Høj/1/Sand/Tændt
  delay(1000);
  digitalWrite(ledPin, LOW); // LED'ens I/O Pin Gøres Lav/0/Falsk/Slukket
  delay(1000);
  
  // Herefter kører loopet igen.
}
