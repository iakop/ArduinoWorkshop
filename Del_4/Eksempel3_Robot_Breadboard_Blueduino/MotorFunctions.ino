// Initializes the left motor's pins:
void motorInitL(){
  // Set all the pins to output, and write LOW to them:
  pinMode(L_EN, OUTPUT);
  digitalWrite(L_EN, LOW);
  pinMode(L_FWD, OUTPUT);
  digitalWrite(L_FWD, LOW);
  pinMode(L_BCK, OUTPUT);
  digitalWrite(L_BCK, LOW);
}

// Initializes the right motor's pins:
void motorInitR(){
  // Set all the pins to output, and write LOW to them:
  pinMode(R_EN, OUTPUT);
  digitalWrite(R_EN, LOW);
  pinMode(R_FWD, OUTPUT);
  digitalWrite(R_FWD, LOW);
  pinMode(R_BCK, OUTPUT);
  digitalWrite(R_BCK, LOW);
}

// Sets the left motor speed from the input. (From -255 to 255)
void motorSpeedL(int spd){
  
  //If the speed is over 0, Set backward low, forward high:
  if(spd > 0){
    digitalWrite(L_BCK, LOW);
    digitalWrite(L_FWD, HIGH);
    analogWrite(L_EN, spd);
  }
  //If the speed is exactly 0, Set everything low:
  else if(spd == 0){
    digitalWrite(L_BCK, LOW);
    digitalWrite(L_FWD, LOW);
    analogWrite(L_EN, spd);
  }
  //If the speed is under 0, Set forward low, backward high:
  else{
    digitalWrite(L_FWD, LOW);
    digitalWrite(L_BCK, HIGH);
    analogWrite(L_EN, -spd);
  }
}

// Sets the right motor speed from the input. (From -255 to 255)
void motorSpeedR(int spd){
  //If the speed is over 0, Set backward low, forward high:
  if(spd > 0){
    digitalWrite(R_BCK, LOW);
    digitalWrite(R_FWD, HIGH);
    analogWrite(R_EN, spd);
  }
  //If the speed is exactly 0, Set everything low:
  else if(spd == 0){
    digitalWrite(R_BCK, LOW);
    digitalWrite(R_FWD, LOW);
    analogWrite(R_EN, spd);
  }
  //If the speed is under 0, Set forward low, backward high:
  else{
    digitalWrite(R_FWD, LOW);
    digitalWrite(R_BCK, HIGH);
    analogWrite(R_EN, -spd);
  }
}
