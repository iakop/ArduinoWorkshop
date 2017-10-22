#include <SoftwareSerial.h>

#define EN 9 // EN bruges til at sætte HC-05 i AT mode.

SoftwareSerial HC05(10,11); // HC05 pins - RX pin 11, TX pin 10

void setup() {
  
  pinMode(EN, OUTPUT);
  digitalWrite(EN, HIGH);
  Serial.begin(9600); // Start serial kommunikation med computeren.
  Serial.println("Enter AT-Commands:"); // Prompt for AT kommandoer.
  HC05.begin(38400); // Sætter HC05 serial hastigheden til 38400 baud. AT mode standardhastighed.

}

void loop() {
  
  // Læser fra HC05 forbindelsen, og skriver det til Arduinos serial.
  if(HC05.available()){
    Serial.write(HC05.read());
  }
  
  // Læser fra Arduino, og sender til HC05:
	// AT-Commands kan findes i en HC-05_AT_commands.pdf
	// Giv modulet et navn med AT+NAME=navn
	// Sæt et nyt kodeord vha. AT+PSWD=kode
	// HUSK at anvende Carriage return OG newline i Serial forbindelsen.
  if(Serial.available()){
    HC05.write(Serial.read());
  }
  
}
