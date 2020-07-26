//Written by Rupak Poddar
//BEFORE UPLOADING, MAKE SURE THAT YOUR DATABASE ".read" AND ".write" RULES ARE SET TO 'true'.
//For more details- https://github.com/Rupakpoddar/ESP8266Firebase/blob/master/README.md
#include <ESP8266Firebase.h>  //https://github.com/Rupakpoddar/ESP8266Firebase
#include <ESP8266WiFi.h>

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
