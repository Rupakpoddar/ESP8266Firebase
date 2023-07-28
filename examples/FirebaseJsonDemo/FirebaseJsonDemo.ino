/*
  Make sure your Firebase project's ".read" and ".write" rules are set to "true".
  Avoiding this will result in an error.
  For more details- https://github.com/Rupakpoddar/ESP8266Firebase/blob/master/README.md
*/

#include <ArduinoJson.h>          // https://github.com/bblanchon/ArduinoJson
#include <ESP8266Firebase.h>
#include <ESP8266WiFi.h>

#define _SSID "ENTER HERE"        // Your WiFi SSID
#define _PASSWORD "ENTER HERE"    // Your WiFi Password
#define PROJECT_ID "ENTER HERE"   // Your Firebase Project ID. Can be found in project settings.

Firebase firebase(PROJECT_ID);

void setup() {
  Serial.begin(115200);
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
  Serial.print("IP Address: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  digitalWrite(LED_BUILTIN, HIGH);

//================================================================//
//================================================================//

  // Write some data to the realtime database.
  firebase.setString("Example/setString", "It's Working");
  firebase.setInt("Example/setInt", 123);
  firebase.setFloat("Example/setFloat", 45.32);

  firebase.json(true);              // Make sure to add this line.
  
  String data = firebase.getString("Example");  // Get data from the database.

  // Deserialize the data.
  // Consider using Arduino Json Assistant- https://arduinojson.org/v6/assistant/
  const size_t capacity = JSON_OBJECT_SIZE(3) + 50;
  DynamicJsonDocument doc(capacity);

  deserializeJson(doc, data);

  // Store the deserialized data.
  const char* received_String = doc["setString"]; // "It's Working"
  int received_int = doc["setInt"];               // 123
  float received_float = doc["setFloat"];         // 45.32

  // Print data
  Serial.print("Received String:\t");
  Serial.println(received_String);

  Serial.print("Received Int:\t\t");
  Serial.println(received_int);

  Serial.print("Received Float:\t\t");
  Serial.println(received_float);

  // Delete data from the realtime database.
  firebase.deleteData("Example");
}

void loop() {
  // Nothing
}
