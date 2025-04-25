#include <Servo.h>

Servo servo;

long pinA = 2;
long pinB = 3;
long pinC = 4;
long pinD = 5;
long pinE = 6;
long pinF = 7;
long pinG = 8;

long C1 = 9;
long C2 = 10;
long C3 = 11;
long C4 = 12;

int slot = 1;
int counter = 0;

void setup() {
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(C3, OUTPUT);
  pinMode(C4, OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);
  servo.attach(13);
  Serial.begin(9600);
}

void AssistParking(){ // Assists the driver to park
  int park = analogRead(A0);
  Serial.println(park);
  delay(10);
  digitalWrite(A4, HIGH); // Turns on LED
  digitalWrite(A5, HIGH); // Turns on Buzzer
  switch (park) {
  case 971 ... 2000: //This is the range where the driver must stop
    SSDSTOP(); //Displays stop
    digitalWrite(A4, HIGH);
    digitalWrite(A5, HIGH);
    counter++; //Counts how long the driver is in the stop zone
    if (counter >= 300) {
      slot = 2; //Switches the current state, from parking state to parked state
    }
    break;
  case 920 ... 970: //This is the range where the driver is near from an obstacle but still safe to back up
    SSDNEAR();
    delay(250);
    digitalWrite(A5, LOW);
    digitalWrite(A4, LOW);
    delay(250);
    break;
  default: //This is the range where the driver is quite far from an obstacle and is safe to back up
    SSDSAFE();
    delay(500);
    digitalWrite(A5, LOW);
    digitalWrite(A4, LOW);
    delay(500);
    break;
  }



}

void SSDSAFE(){ //Prints the word SAFE
  print4();
  letterS();
  print3();
  letterA();
  print2();
  letterF();
  print1();
  letterE();
}

void SSDNEAR(){ //Prints the word NEAR
  print4();
  letterN();
  print3();
  letterE();
  print2();
  letterA();
  print1();
  letterR();
}

void SSDSTOP(){ //Prints the word STOP4
  print4();
  letterS();
  print3();
  letterT();
  print2();
  letterO();
  print1();
  letterP();
}

void SSDOPEN(){ //Prints the word OPEN
  print4();
  letterO();
  print3();
  letterP();
  print2();
  letterE();
  print1();
  letterN();
}

void SSDGOOD(){ //Prints the word GOOD
  print4();
  letterG();
  print3();
  letterO();
  print2();
  letterO();
  print1();
  letterD();
}

void SSDOFF(){ //Closes all the SSD
  print4();
  letterOff();
  print3();
  letterOff();
  print2();
  letterOff();
  print1();
  letterOff();
}

void print1() {//prints to digit 1 on display
  delay(1);
  digitalWrite(C1, LOW);
  digitalWrite(C2, HIGH);
  digitalWrite(C3, HIGH);
  digitalWrite(C4, HIGH);
}

void print2() {//prints to digit 2 on display
  delay(1);
  digitalWrite(C1, HIGH);
  digitalWrite(C2, LOW);
  digitalWrite(C3, HIGH);
  digitalWrite(C4, HIGH);
}
void print3() {//prints to digit 3 on display
  delay(1);
  digitalWrite(C1, HIGH);
  digitalWrite(C2, HIGH);
  digitalWrite(C3, LOW);
  digitalWrite(C4, HIGH);
}

void print4() {//prints to digit 4 on display
  delay(1);
  digitalWrite(C1, HIGH);
  digitalWrite(C2, HIGH);
  digitalWrite(C3, HIGH);
  digitalWrite(C4, LOW);
}

void letterS() {
  //prints S
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void letterA() {
  //prints A
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void letterF() {
  //prints F
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}
void letterE() {
  //prints E
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void letterN() {
  //prints N
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}

void letterR() {
  //prints R
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}

void letterT() {
  //prints T
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void letterO() {
  //prints O
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}

void letterP() {
  //prints P
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void letterG() {
  //prints G
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void letterD() {
  //prints D
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}

void letterOff() {
  //prints blank
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void AssistLeaving(){ //Assists leaving drivers
  int park = analogRead(A0);
  if(830 < park < 950){
    MOVESERVO();
  }
}

void MOVESERVO(){ //Imitates the motion of parking assistant
  servo.write(120);
  delay(250);
  servo.write(70);
  delay(250);
}

void loop() {
  int park = analogRead(A0);
  Serial.println(park);
  delay(10);
  switch (slot) { //chooses the state of the driver
  case 0: //Driver Leaving State
    AssistLeaving();
    digitalWrite(A5, LOW);
    if(park <= 840) { //checks if the car is gone
      slot = 1;//Switches the current state, from leaving state to vacant state
      servo.write(70);
    }
    break;
  case 1: //Vacant Parking Slot
    if(park > 835){//Checks if there is a parking car, if there is then it starts assisting the driver
        AssistParking();
      }
      else if(park > 100){//Checks if there is a parking car, if there is not, then it displays open and LED is turned on
        digitalWrite(A4, HIGH);
        digitalWrite(A5, LOW);
        counter = 0;
        SSDOPEN();
      }
    break;
  case 2://Car is Parked State
    SSDGOOD();
    digitalWrite(A4, LOW);
    digitalWrite(A5, LOW);
    if(park <= 950) {//Detects movement from a parked car
      SSDOFF();
      slot = 0;//Switches the current state, from parked state to leaving state
    }
    break;
  }
}

