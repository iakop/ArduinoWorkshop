#include <SoftwareSerial.h> // Include the SoftwareSerial library for serial emulation.

// Left motor's Enable, Forward and Back pins: 
#define L_EN 5
#define L_FWD 4
#define L_BCK 3

// Right motor's Enable, Forward and Back pins:
#define R_EN 6
#define R_FWD 7
#define R_BCK 8

// Virtual RX and TX pins for HC-05 communication:
#define V_RX 10
#define V_TX 11

// Define the legal button inputs:
#define UP "b=1"
#define DOWN "b=2"
#define LEFT "b=3"
#define RIGHT "b=4"

SoftwareSerial HC05(V_RX,V_TX); // Virtual serial connection to the HC-05 Module.

String data; // Datastring for the HC-05 messages.

void setup(){
  motorInitL(); // Initialization function for the left motor.
  motorInitR(); // Initialization function for the right motor.
  HC05.begin(115200); // Initiealizes the communication with HC-05 at 115200 baud.
}

void loop(){

  // Check for new messages from HC-05 module:
  if(HC05.available() > 0){
      data = HC05.readStringUntil('#');
  }

  // If the up button is pressed on joypad:
  if(data.equals(UP)){
    motorSpeedL(255);
    motorSpeedR(255);
  }
  // If the down button is pressed on joypad:
  else if(data.equals(DOWN)){
    motorSpeedL(-255);
    motorSpeedR(-255);
  }
  // If the left button is pressed on joypad:
  else if(data.equals(LEFT)){
    motorSpeedL(0);
    motorSpeedR(255);
  }
  // If the right button is pressed on joypad:
  else if(data.equals(RIGHT)){
    motorSpeedL(255);
    motorSpeedR(0);
  }
  // If no defined button is pressed on joypad:
  else{
    motorSpeedL(0);
    motorSpeedR(0);
  }
}

