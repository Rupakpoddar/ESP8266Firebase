//Written by Rupak Poddar

//BEFORE UPLOADING, MAKE SURE THAT YOUR DATABASE ".read" AND ".write" RULES ARE SET TO 'true'.

//For more details- https://github.com/Rupakpoddar/ESP8266Firebase/blob/master/README.md

//Download the Android app from- https://play.google.com/store/apps/details?id=com.rupak.firebaseremote

#include <ESP8266Firebase.h>  //https://github.com/Rupakpoddar/ESP8266Firebase
#include <ESP8266WiFi.h>

const char *ssid = "Change_this";      //Your Wi-Fi SSID
const char *password = "Change_this"; //Your Wi-Fi password

#define projectID "YOUR PROJECT ID" //Your Firebase Project ID; can be found in project settings.

#define m1a 5   //D1 output 1 for motor driver
#define m1b 4   //D2 output 2 for motor driver
#define m2a 0   //D3 output 3 for motor driver
#define m2b 14  //D5 output 4 for motor driver

int interval = 100; //Turn left or right delay

void setup() 
{
  Serial.begin(115200);

  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);

  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);

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

void loop() 
{
  Firebase firebase(projectID); //Create an object.

  int command = firebase.getInt("cmd/Robot");  //Get data from the database.
  
   if(command == 0)  //Stop                                                       
     {
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, LOW);
    }

   if(command == 1) //Forward motion                                                          
     {
      digitalWrite(m1a, HIGH);
      digitalWrite(m2a, HIGH);
      delay(500);
      digitalWrite(m1a, LOW);
      digitalWrite(m2a, LOW);
    }

   
   if(command == 2) //Backward motion                                                           
     {
      digitalWrite(m1b, HIGH);
      digitalWrite(m2b, HIGH);
      delay(500);
      digitalWrite(m1b, LOW);
      digitalWrite(m2b, LOW);
    }

   
   if(command == 3) //Turn left                                                             
     {
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, HIGH);
      delay(interval);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      
    }

   
   if(command == 4) //Turn right                                                            
     {
      digitalWrite(m1a, HIGH);
      digitalWrite(m2b, HIGH);
      delay(interval);
      digitalWrite(m1a, LOW);
      digitalWrite(m2b, LOW);
    }
}
