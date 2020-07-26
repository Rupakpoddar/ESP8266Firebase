//Written by Rupak Poddar

//BEFORE UPLOADING, MAKE SURE THAT YOUR DATABASE ".read" AND ".write" RULES ARE SET TO 'true'.

//For more details- https://github.com/Rupakpoddar/ESP8266Firebase/blob/master/README.md

//Download the Android app from- https://play.google.com/store/apps/details?id=com.rupak.firebaseremote

//Online remote (Works on any web browser)- https://rupakpoddar.github.io/Firebase-automation-web-interface/

//Use Python to control devices- https://github.com/Rupakpoddar/Firebase-with-python

#include <ESP8266Firebase.h>  //https://github.com/Rupakpoddar/ESP8266Firebase
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>  //https://github.com/bblanchon/ArduinoJson

const char *ssid = "Change_this";      //Your Wi-Fi SSID
const char *password = "Change_this"; //Your Wi-Fi password

#define projectID "YOUR PROJECT ID" //Your Firebase Project ID; can be found in project settings.

#define device1 5   //D1
#define device2 4   //D2
#define device3 0   //D3
#define device4 14  //D5

int device_list[4] = {device1, device2, device3, device4};

void setup() {
  pinMode(device1, OUTPUT);
  pinMode(device2, OUTPUT);
  pinMode(device3, OUTPUT);
  pinMode(device4, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT); //16
  digitalWrite(LED_BUILTIN, LOW);
  
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);

//Attempt to connect to Wifi network:
  Serial.println("");
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("-");
    delay(500);
  }

  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);
  Serial.println("");
}

void loop() {
Firebase firebase(projectID); //Create an object.

firebase.json(true);  //A component, when set to 'true', returns Json object while calling the "getString" function.
                     //This component is set to 'false' by default.

String data = firebase.getString("cmd");  //Get data from the database.

//Deserialize the data.
//Consider using the Arduino Json assistant- https://arduinojson.org/v6/assistant/
const size_t capacity = JSON_OBJECT_SIZE(5) + 60;
DynamicJsonDocument doc(capacity);

deserializeJson(doc, data);

String Device1 = doc["Device1"]; 
String Device2 = doc["Device2"]; 
String Device3 = doc["Device3"]; 
String Device4 = doc["Device4"]; 
//int Robot = doc["Robot"]; 

//Print data
Serial.println("Device 1: "+Device1);
Serial.println("Device 2: "+Device2);
Serial.println("Device 3: "+Device3);
Serial.println("Device 4: "+Device4);
Serial.println("");

String status_list[4] = {Device1, Device2, Device3, Device4};

for (int i=0;i<4;i++){
  if (status_list[i] == "ON"){
    digitalWrite(device_list[i], HIGH);
  }
  else{
    digitalWrite(device_list[i], LOW);
  }
}
}
