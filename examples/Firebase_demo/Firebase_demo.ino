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
#include <ESP8266Firebase.h>
#include <ESP8266WiFi.h>

const char *ssid = "Change_this";      //Your Wi-Fi SSID 
const char *password = "Change_this"; //Your Wi-Fi password

#define projectID "Change_this"     //Your Firebase Project ID; can be found in project settings.

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

//Examples of setting String, integer and float values.
firebase.setString("Example/setString", "It's Working");
firebase.setInt("Example/setInt", 123);
firebase.setFloat("Example/setFloat", 45.32);

//Examples of pushing String, integer and float values.
firebase.pushString("push", "Hello");
firebase.pushInt("push", 789);
firebase.pushFloat("push", 89.54);

//Example of getting a String.
String data1 = firebase.getString("Example/setString");
Serial.print("Received String: ");
Serial.println(data1);

//Example of getting an int.
int data2 = firebase.getInt("Example/setInt");
Serial.print("Received int: ");
Serial.println(data2);

//Example of getting a float.
float data3 = firebase.getFloat("Example/setFloat");
Serial.print("Received float: ");
Serial.println(data3);

//Example of data deletion.
firebase.deleteData("Example");
}

void loop() {
}
