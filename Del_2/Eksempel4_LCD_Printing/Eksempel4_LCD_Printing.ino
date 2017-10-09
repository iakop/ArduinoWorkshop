#include <LiquidCrystal.h> // Vi indlæser LiquidCrystal biblioteket.

#define RS 3
#define E 4
#define D4 5
#define D5 6
#define D6 7
#define D7 8
// RW til GND
// VSS til GND
// VDD til 5V
// 10k potmeter mellem GND VO og VDD
// A forbindes med en 220 ohms resistor til +5V og en K til GND.

#define BTN 2 // Knappen sidder på pin 2.

//Vores Helt eget tegn:
byte blinkey[8] =
{
  B00000,
  B11001,
  B00000,
  B00000,
  B11111,
  B01001,
  B00110
};

LiquidCrystal lcd(RS, E, D4, D5, D6, D7); // Vi constructer et objekt lcd af typen Liquid Crystal.

unsigned int count = 0; // count er den tællerværdi vi vil skrive ud i sidste ende.
long unsigned int wait = 0; // wait er en timervariabel, der hjælper os med at holde styr på ventetiden for knappen.

void setup() {
  pinMode(BTN, INPUT); // BTN sættes op som input.
  
  lcd.createChar(0, blinkey); // createChar funktionen bruges til at sætte vores eget tegn op.
  
  lcd.begin(16, 2); // LCD'et opsættes med 2 linjer, 16 chars.
  
  lcd.setCursor(0 /*x*/ , 0 /*y*/); // Cursoren for displayet sættes på koordinaterne 0,0.
  lcd.print("Hello world! "); // Vi udskriver Hello World.
  
  lcd.write(byte(0)); // Vi skriver vores eget tegn.
}

void loop() {
  // Vi behøver kun ændre noget, hvis der trykkes på knappen:
  if (digitalRead(BTN) == HIGH && wait <= (millis() - 100)) //Hvis knappen er høj, og ventetimeren er 100 ms efter systemtimeren.
  {
    wait = millis(); // Ventetimeren opdateres.
    count++; // Count inkrementeres med 1.
    
    lcd.setCursor(0, 1); // Sæt cursoren ned på den rigtige plads.
    lcd.print(count); // Udskriv count.
    
    while(digitalRead(BTN) == HIGH); // TRICK! Programmet laver intet i en while-løkke der bare er while(cond);
    delay(50); // Når knappen går ned fra HIGH igen, vent 50ms.
  }
}