#include <WiFi.h>
#include <HTTPClient.h>

//Sensors
const int sensor1Pin = 14;
const int sensor2Pin = 35;

String URL = "http://192.168.135.206/parking_project/test_data.php";

const char* ssid = "itel P55 5G";
const char* password = "pldtwifi";

int sensor1Value;
int sensor2Value;


String status1 = "";
String status2 = ""; //Status for another sensor
String postData = "";

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

  Serial.begin(115200);
  connectWiFi();
}

void loop() {

  if(WiFi.status() != WL_CONNECTED) {
    connectWiFi();
  }

  readSensor();

  HTTPClient http;
  http.begin(URL);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded"); //helps server understand the type of data being sent

  int httpCode = http.POST(postData);
  String payload = http.getString(); //response from server
  
  Serial.print("URL : ");
  Serial.println(URL);
  Serial.print("Data : ");
  Serial.println(postData);
  Serial.print("httpCode : ");
  Serial.println(httpCode);
  Serial.print("payload : ");
  Serial.println(payload);
  Serial.println("--------------------------------------------------");

}

void connectWiFi() {
  WiFi.mode(WIFI_OFF);
  delay(1000);

  WiFi.mode(WIFI_STA);

  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print("connected to : ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void readSensor() {
  sensor1Value = analogRead(sensor1Pin);
  sensor2Value = analogRead(sensor2Pin);


  status1 = (sensor1Value < 600) ? "Parked" : "Vacant";
  status2 = (sensor2Value < 600) ? "Parked" : "Vacant";

  postData = "id1=1&status1=" + status1 + "&id2=2&status2=" + status2;

  Serial.printf("Value: %d\n", sensor1Value);
  Serial.printf("Value: %d\n", sensor2Value);
}