/*
  Make sure your Firebase project's '.read' and '.write' rules are set to 'true'. 
  Ignoring this will prevent the MCU from communicating with the database. 
  For more details- https://github.com/Rupakpoddar/ESP8266Firebase 
*/

#include <ArduinoJson.h>            // https://github.com/bblanchon/ArduinoJson 
#include <ESP8266Firebase.h>
#include <ESP8266WiFi.h>

#define _SSID         "ENTER HERE"  // Your WiFi SSID
#define _PASSWORD     "ENTER HERE"  // Your WiFi Password
#define API_KEY       "ENTER HERE"  // Your Firebase project Web Api Key
#define AUTH_TOKEN    "ENTER HERE"  // Your Firebase project Database Secrets
#define REFERENCE_URL "ENTER HERE"  // Your Firebase project reference url
#define USER_EMAIL    "ENTER HERE"  // Your Firebase project Authentication (Email)
#define USER_PASSWORD "ENTER HERE"  // Your Firebase project Authentication (Password)

Firebase firebase;

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

  // Initialize Firebase Library
  // firebase.setBufferSize(4096, 1024); // Optional input
  firebase.begin(REFERENCE_URL, API_KEY, AUTH_TOKEN);
  firebase.signIn(USER_EMAIL, USER_PASSWORD);

  // Test Set data to database.
  // Create DynamicJsonDocument object
  // Consider using Arduino Json Assistant- https://arduinojson.org/v6/assistant/
  const size_t capacity = JSON_OBJECT_SIZE(3) + 50;
  DynamicJsonDocument doc(capacity);
  String setdata = "";

  // Write some data to the realtime database.
  doc["setString"] = "It's Working";
  doc["setInt"] = 123;
  doc["setFloat"] = 45.32;

  // Serialize the data
  serializeJson(doc, setdata);
  firebase.set("Example", setdata);
  
  // Test Get data from database.
  String data = firebase.get("Example");  // Get data from the database.
  // Deserialize the data.
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
  firebase.del("Example");
}

void loop() {
  // Nothing
}
