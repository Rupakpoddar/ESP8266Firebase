/*
MIT License

Copyright (c) 2020 Rupak Poddar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

//BEFORE UPLOADING, MAKE SURE THAT YOUR DATABASE ".read" AND ".write" RULES ARE SET TO 'true'.
//For more details- https://github.com/Rupakpoddar/ESP8266Firebase/blob/master/README.md
#include <ESP8266Firebase.h>  //https://github.com/Rupakpoddar/ESP8266Firebase
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>  //https://github.com/bblanchon/ArduinoJson

const char *ssid = "Change_this";      //Your Wi-Fi SSID
const char *password = "Change_this"; //Your Wi-Fi password

#define projectID "YOUR PROJECT ID" //Your Firebase Project ID; can be found in project settings.

void setup() {
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
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);
  Serial.println("");

Firebase firebase(projectID); //Create an object.

//Write some data to the realtime database.
firebase.setString("Example/setString", "It's Working");
firebase.setInt("Example/setInt", 123);
firebase.setFloat("Example/setFloat", 45.32);

firebase.json(true);  //A component, when set to 'true', returns Json object while calling the "getString" function.
                     //This component is set to 'false' by default.

String data = firebase.getString("Example");  //Get data from the database.

//Deserialize the data.
//Consider using the Arduino Json assistant- https://arduinojson.org/v6/assistant/
const size_t capacity = JSON_OBJECT_SIZE(3) + 50;
  DynamicJsonDocument doc(capacity);

deserializeJson(doc, data);

//Store the deserialized data.
const char* received_String = doc["setString"]; // "It's Working"
int received_int = doc["setInt"]; // 123
float received_float = doc["setFloat"]; // 45.32

//Print data
Serial.print("Received String: ");
Serial.println(received_String);

Serial.print("Received int: ");
Serial.println(received_int);

Serial.print("Received float: ");
Serial.println(received_float);

//Delete data from the realtime database.
firebase.deleteData("Example");
}

void loop() {
}
