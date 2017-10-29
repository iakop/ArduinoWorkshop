#include <SoftwareSerial.h>

String data; // String der holder det modtagne data.

SoftwareSerial HC05(10,11); // HC05 pins - RX pin 10, TX pin 11.

void setup()
{
    Serial.begin(9600); // Start serial kommunikation med computeren.
    HC05.begin(115200); // Start serial kommunikation med HC-05 modulet.                              
}
void loop()
{
   if(HC05.available() > 0) // Tjekker om der er data tilgængeligt.
   {
      data = HC05.readStringUntil('#'); // Indlæs en streng fra HC-05 til data, alt der ligger mellem stopkaraktererne '#'.
      Serial.println(data);
   }
}
