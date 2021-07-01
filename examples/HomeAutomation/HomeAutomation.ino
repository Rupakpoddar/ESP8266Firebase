/*
  Make sure your Firebase project's ".read" and ".write" rules are set to "true".
  Avoiding this will result in an error.
  For more details- https://github.com/Rupakpoddar/ESP8266Firebase/blob/master/README.md

  Download the Android app from- https://play.google.com/store/apps/details?id=com.rupak.firebaseremote
  Online remote (Works with any web browser)- https://rupakpoddar.github.io/Firebase-automation-web-interface/
  Use Python to control devices- https://github.com/Rupakpoddar/Firebase-with-python
*/

#include <ArduinoJson.h>          // https://github.com/bblanchon/ArduinoJson
#include <ESP8266Firebase.h>
#include <ESP8266WiFi.h>

#define _SSID "ENTER HERE"        // Your WiFi SSID
#define _PASSWORD "ENTER HERE"    // Your WiFi Password
#define PROJECT_ID "ENTER HERE"   // Your Firebase Project ID. Can be found in project settings.

#define device1 5   // D1
#define device2 4   // D2
#define device3 0   // D3
#define device4 14  // D5
int device_list[4] = {device1, device2, device3, device4};

/*
  // FAST METHOD
  // REQUIRES PERIODIC UPDATE OF FINGERPRINT (EVERY 1 YEAR)
  // OUTDATED FINGERPRINT WILL STOP THE SERVICE
  // LATEST FINGERPRINT CAN BE FOUND AT- https://www.grc.com/fingerprints.htm?domain=test.firebaseio.com
  // REPLACE COLONS(:) WITH A SPACE(" ") AS SHOWN BELOW
  // 03:9E:4F:E6:83:FC:40:EF:FC:B2:C5:EF:36:0E:7C:3C:42:20:1B:8F ==> 03 9E 4F E6 83 FC 40 EF FC B2 C5 EF 36 0E 7C 3C 42 20 1B 8F
  #define FINGERPRINT "03 9E 4F E6 83 FC 40 EF FC B2 C5 EF 36 0E 7C 3C 42 20 1B 8F"
  Firebase firebase(PROJECT_ID, FINGERPRINT);
  // UNCOMMENT THIS BLOCK AND COMMENT THE LINE BELOW
*/

Firebase firebase(PROJECT_ID);    // SLOW BUT HASTLE-FREE METHOD FOR LONG TERM USAGE. DOES NOT REQUIRE PERIODIC UPDATE OF FINGERPRINT

void setup() {
  Serial.begin(115200);
  firebase.json(true);
  pinMode(device1, OUTPUT);
  pinMode(device2, OUTPUT);
  pinMode(device3, OUTPUT);
  pinMode(device4, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);

  // Connect to WiFi
  Serial.println();
  Serial.println();
  Serial.print("Connecting to: ");
  Serial.println(_SSID);
  WiFi.begin(_SSID, _PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("-");
  }

  Serial.println("");
  Serial.println("WiFi Connected");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  String data = firebase.getString("cmd");  // Get data from database.

  // Deserialize the data.
  // Consider using the Arduino Json assistant- https://arduinojson.org/v6/assistant/
  const size_t capacity = JSON_OBJECT_SIZE(5) + 60;
  DynamicJsonDocument doc(capacity);

  deserializeJson(doc, data);

  String Device1 = doc["Device1"];
  String Device2 = doc["Device2"];
  String Device3 = doc["Device3"];
  String Device4 = doc["Device4"];

  // Print data
  Serial.println("Device 1: "+Device1);
  Serial.println("Device 2: "+Device2);
  Serial.println("Device 3: "+Device3);
  Serial.println("Device 4: "+Device4);
  Serial.println("");

  String status_list[4] = {Device1, Device2, Device3, Device4};

  for (int i=0;i<4;i++) {
    if (status_list[i] == "ON"){
      digitalWrite(device_list[i], HIGH);
    }
    else{
      digitalWrite(device_list[i], LOW);
    }
  }
}
