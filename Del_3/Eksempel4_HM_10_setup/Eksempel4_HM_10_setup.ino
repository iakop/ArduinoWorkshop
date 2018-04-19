#include <SoftwareSerial.h>

#define EN 9 // EN bruges til at sætte HC-05 i AT mode.

SoftwareSerial HM10(10,11); // HC05 pins - RX pin 11, TX pin 10

void setup() {
  
  pinMode(EN, OUTPUT);
  digitalWrite(EN, HIGH);
  Serial.begin(9600); // Start serial kommunikation med computeren.
  Serial.println("Enter AT-Commands:"); // Prompt for AT kommandoer.
  HM10.begin(9600); // S?tter HC05 serial hastigheden til 9600 baud. AT mode standardhastighed.

}

void loop() {
  
  // Læser fra HM10 forbindelsen, og skriver det til Arduinos serial.
  if(HM10.available()){
    Serial.write(HM10.read());
  }
  
  // Læser fra Arduino, og sender til HC05:
	// AT-Commands kan findes i en HC-05_AT_commands.pdf
	// Giv modulet et navn med AT+NAME[navn]
	// Sæt et nyt kodeord vha. AT+PIN[kode]
	// Sæt baud-rate til 115200: AT+BAUD4
  // Sæt stop bit til 1: AT+STOP0
  // Sæt Parity til ingen: AT+PARI0
	// HUSK at anvende Carriage return OG newline i Serial forbindelsen.
  if(Serial.available()){
    HM10.write(Serial.read());
  }
  
}
