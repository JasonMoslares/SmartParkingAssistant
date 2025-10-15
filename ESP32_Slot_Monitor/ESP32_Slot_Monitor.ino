#include <WiFi.h>
#include <HTTPClient.h>

#define RXp2 16
#define TXp2 17

String URL = "http://YOUR_IP_ADDRESS/parking_project/parking_data.php";

const char* ssid = "SSID_NAME";
const char* password = "SSID_PASSWORD";

String state = "";                                               // State from Arduino
String lastState = "";
String postData = "";
int id = 1;                                                      // Replace depending on which Lot

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
  connectWiFi();
}

void loop() {

  if(WiFi.status() != WL_CONNECTED) {
    connectWiFi();
  }
  
  if (Serial2.available()) {
    state = Serial2.readStringUntil('\n');
    state.trim();
  }

  updateData();

  Serial.println(state);
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

void updateData() {
  if (state.length() > 0 && state != lastState) {
    lastState = state;
    postData = "id=" + String(id) + "&status=" + state;
    sendToPhp();
  }
}


void sendToPhp(){
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(URL);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");          // helps server understand the type of data being sent

    int httpCode = http.POST(postData);
    String payload = http.getString();                                            // response from server
  
    Serial.printf("[Lot %d] Data sent (HTTP %d): %s\n", id, httpCode, payload.c_str());
    Serial.println("--------------------------------------------------");
    http.end();
  }
  else {
    Serial.printf("[Lot %d] WiFi not connected. Skipping POST.\n", id);
  }
}