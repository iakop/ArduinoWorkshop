# ArduinoWorkshop
På denne workshop er det primære formål at stifte bekendtskab med programmeringen, elektronikken og udviklingsmiljøet omkring Arduinoplatformen. Det består af fire gange:

- Del 1 – Introduktion, Digital og Analog elektronik

- Del 2 – Motorer, displays og anden output

- Del 3 – Fjernstyring, motorstyring og Arduino C

- Del 4 – Sammenkobling af det lærte, Byg en Bluetooth-styret robot!

Der vil først blive undervist i hvordan man bygger nogle praktiske kredsløb op omkring Arduino. Herefter vil forskellige outputmetoder blive udforsket, heriblandt servomotorer, steppermotorer og LED-displays samt LCD.
Den resterende halvdel kommer til at arbejde mere fokuseret på at bygge en køredygtig robot, som kan styres med Bluetooth fra en Joystick App. Til sidst vil der være plads til en lille robotkonkurrence!

Workshoppen er baseret på følgende komponenter:
https://www.aliexpress.com/item/4001217353266.html - Geekcreit Arduino Uno Kit
https://www.aliexpress.com/item/4000146001648.html - 2WD Smart Robot Car Chassis
https://www.aliexpress.com/item/32612978653.html - HC-05 Bluetooth Transciever
https://www.aliexpress.com/item/1005002353427075.html - L293D Motor Driver

______________________________________________________________________________________

## INFO til d. 26. april 2018
Jeg har undersøgt sagen med Bluetooth modulerne, og de HM-10 moduler jeg har modtaget er af typen CC41-a, som er baseret på CC2541-chippen fra texas instruments, der kan cirka det samme som CC2540, der sidder i "ægte" HM-10'ere. Firmwaren er blot lidt forskellig, hvorfor AT-kommandoerne de tager heller ikke fortolkes ens.

Jeg har uploadet HM-10 firmware til CC41-a modulet, og min android kan også paire med den. Dog giver dette ikke nogen mærkbar forbedring i funktionalitet, når det bliver brugt sammen med en fjernstyringsapp.

### Hvad vi gør
Hvis man har android vil jeg anbefale at vælge HC-05!!!
Den virker og er testet med mine eksempler. Derudover har jeg fundet en god app, ud over Arduino BT Joystick Free.

Download Arduino Bluetooth RC Car, dens UI fungerer lidt bedre til de opgaver robotten skal udføre, og så er dens serial strings lettere at parse. :)

Hvis man ikke har en Android, men en Windows PC, kan man bruge stadig bruge Blueduino med HC-05. Men appen virker umiddelbart ustabil, så jeg vil foreslå at vælge Android hvis man kan.

Til sidst, hvis man af en eller anden grund ikke kan få PC til at virke, eller ikke har Android, kan man med iPhone troubleshoote sit modul vha. appen LightBlue (Udviklet af en konsulentvirksomhed i Bluetooth, det burde sige noget om hvor tarvelig teknologien er at arbejde med). Den kan tilgå vores devices uden Pairing og sende rene datapakker. I iPhone appen, kan man ændre datatype til strings, og sende sine egne beskeder, der kan fortolkes som frem, tilbage osv. :)

Håber det hjælper, ellers blot forsøg at bygge robotkredsløbene fra Del 4 materialet, og så kan vi se på at ordne bluetooth misæren én gang for alle i morgen!
