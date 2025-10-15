#include <Servo.h>

Servo servo;

const int pinA = 2;
const int pinB = 3;
const int pinC = 4;
const int pinD = 5;
const int pinE = 6;
const int pinF = 7;
const int pinG = 8;

const int C1 = 9;
const int C2 = 10;
const int C3 = 11;
const int C4 = 12;

const int photoSensor = A0;
const int light = A4;
const int buzzer = A5;

String state = "Vacant";                                                                                // States are vacant by default;
String lastState = "";

unsigned long prevMillis = 0;
bool lightState = false;

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

  pinMode(light,OUTPUT);
  pinMode(buzzer,OUTPUT);

  servo.attach(13);
  Serial.begin(9600);
}

void SSDSAFE(){                                                                                // Prints the word SAFE
  print4();
  letterS();
  print3();
  letterA();
  print2();
  letterF();
  print1();
  letterE();
}

void SSDNEAR(){                                                                                // Prints the word NEAR
  print4();
  letterN();
  print3();
  letterE();
  print2();
  letterA();
  print1();
  letterR();
}

void SSDSTOP(){                                                                                // Prints the word STOP
  print4();
  letterS();
  print3();
  letterT();
  print2();
  letterO();
  print1();
  letterP();
}

void SSDOPEN(){                                                                                // Prints the word OPEN
  print4();
  letterO();
  print3();
  letterP();
  print2();
  letterE();
  print1();
  letterN();
}

void SSDGOOD(){                                                                                // Prints the word GOOD
  print4();
  letterG();
  print3();
  letterO();
  print2();
  letterO();
  print1();
  letterD();
}

void SSDOFF(){                                                                                 // Closes all the SSD
  print4();
  letterOff();
  print3();
  letterOff();
  print2();
  letterOff();
  print1();
  letterOff();
}

void print1() {                                                                                // Prints to digit 1 on display
  delay(1);
  digitalWrite(C1, LOW);
  digitalWrite(C2, HIGH);
  digitalWrite(C3, HIGH);
  digitalWrite(C4, HIGH);
}

void print2() {                                                                                // Prints to digit 2 on display
  delay(1);
  digitalWrite(C1, HIGH);
  digitalWrite(C2, LOW);
  digitalWrite(C3, HIGH);
  digitalWrite(C4, HIGH);
}

void print3() {                                                                                // Prints to digit 3 on display
  delay(1);
  digitalWrite(C1, HIGH);
  digitalWrite(C2, HIGH);
  digitalWrite(C3, LOW);
  digitalWrite(C4, HIGH);
}

void print4() {                                                                                // Prints to digit 4 on display
  delay(1);
  digitalWrite(C1, HIGH);
  digitalWrite(C2, HIGH);
  digitalWrite(C3, HIGH);
  digitalWrite(C4, LOW);
}

void letterS() {                                                                               // Prints S using 7 SSD
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void letterA() {                                                                               // Prints A using 7 SSD
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void letterF() {                                                                               // Prints F using 7 SSD
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void letterE() {                                                                               // Prints E using 7 SSD
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void letterN() {                                                                               // Prints N using 7 SSD
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}

void letterR() {                                                                               // Prints R using 7 SSD
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}

void letterT() {                                                                               // Prints T using 7 SSD
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void letterO() {                                                                               // Prints O using 7 SSD
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}

void letterP() {                                                                               // Prints P using 7 SSD
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void letterG() {                                                                               // Prints G
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void letterD() {                                                                               // Prints D
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}

void letterOff() {                                                                             // Turns off SSD
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void AssistParking(int reading){                                                               // Assists the driver to park
  delay(10);

  if (reading >= 971){
    SSDSTOP();                                                                                 // Displays stop
    digitalWrite(light, HIGH);                                                                 // Fixed the light to prompt the driver to stop
    digitalWrite(buzzer, HIGH);                                                                // Produces sound to prompt the driver to stop                
    if (millis() - prevMillis >= 3000) {
      state = "Parked";                                                                        // If the driver is stationary in the STOP zone, it switches the current state, from vacant state to parked state
    }
  }

  else if (reading >= 920 && reading <= 970){                                                  // This is the range where the driver is near from an obstacle but still safe to back up
    SSDNEAR();
    blinkLight(250);                                                                           // toggles every 250 ms
  }

  else{                                                                                        // This is the range where the driver is quite far from an obstacle and is safe to back up
    SSDSAFE();
    digitalWrite(light, LOW);
    digitalWrite(buzzer, LOW);
  }
}

void AssistLeaving(int reading){                                                               // Assists leaving drivers
  if(reading >= 920 && reading < 970){                                                         // Range from STOP to SAFE 
    MOVESERVO();
  }
}

void MOVESERVO(){                                                                             // Imitates the motion of parking assistant
  servo.write(120);
  delay(250);
  servo.write(70);
  delay(250);
}

void blinkLight(unsigned long interval) {
  if (millis() - prevMillis >= interval) {
    prevMillis = millis();
    lightState = !lightState;                                                                 // toggle ON/OFF
    digitalWrite(light, lightState);
    digitalWrite(buzzer, lightState);
  }
}

void loop() {
  int park = analogRead(photoSensor);
  delay(10);


  if(state == "Leaving"){                                                                     // Driver Leaving State
    AssistLeaving(park);

    if(park <= 920) {                                                                        // Checks if the car is gone
      state = "Vacant";                                                                      // Switches the current state, from leaving state to vacant state
      servo.write(70);                                                                       // Servo's default position
    }
  }                                                                            
  
  else if(state == "Vacant"){                                                                // Vacant Parking Slot
    if(park > 920){                                                                          // Checks if there is a parking car, if there is then it starts assisting the driver
      AssistParking(park);
    }

    else{                                                                                    // If there is not, then it displays open and LED is turned on
      digitalWrite(light, HIGH);
      digitalWrite(buzzer, LOW);
      SSDOPEN();
    }
  }

  else if(state == "Parked"){                                                                // Car is Parked State
    SSDGOOD();
    digitalWrite(light, LOW);
    digitalWrite(buzzer, LOW);
    if(park < 970) {                                                                         // Detects movement from a parked car, if there is then the car is leaving
      SSDOFF();
      state = "Leaving";                                                                     // Switches the current state, from parked state to leaving state)
    }
  }

  if (state != lastState){
    Serial.println(state);                                                                    // Uses UART Serial Communication to send to Esp32
    lastState = state;
  }
}

