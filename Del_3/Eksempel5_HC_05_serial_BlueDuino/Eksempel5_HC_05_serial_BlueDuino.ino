#include <SoftwareSerial.h>

String data; // String der holder det modtagne data.
char * dataStr;
int * dir;

SoftwareSerial HC05(10,11); // HC05 pins - RX pin 11, TX pin 10.

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
      dataStr = (char*)data.c_str();
      dir = (int*)strtok(dataStr,"*,");
      Serial.print((uint8_t)dir[0]);
      Serial.print(" - ");
      Serial.println((uint8_t)dir[1]); // Skriv data ud til computeren.        
   }
}
