/*
  Make sure your Firebase project's ".read" and ".write" rules are set to "true".
  Avoiding this will result in an error.
  For more details- https://github.com/Rupakpoddar/ESP8266Firebase/blob/master/README.md
  Download the Android app from- https://play.google.com/store/apps/details?id=com.rupak.firebaseremote
*/

#include <ESP8266Firebase.h>
#include <ESP8266WiFi.h>

#define _SSID "ENTER HERE"        // Your WiFi SSID
#define _PASSWORD "ENTER HERE"    // Your WiFi Password
#define PROJECT_ID "ENTER HERE"   // Your Firebase Project ID. Can be found in project settings.

#define M1A 5   // D1: Output 1 for motor driver
#define M1B 4   // D2: Output 2 for motor driver
#define M2A 0   // D3: Output 3 for motor driver
#define M2B 14  // D5: Output 4 for motor driver

#define TURN_DELAY 100
#define FORWARD_BACKWARD_DELAY 500

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
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);

  digitalWrite(M1A, LOW);
  digitalWrite(M1B, LOW);
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, LOW);

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
  int command = firebase.getInt("cmd/Robot"); // Get data from database.

  if(command == 0){ //  STOP
    digitalWrite(M1A, LOW);
    digitalWrite(M1B, LOW);
    digitalWrite(M2A, LOW);
    digitalWrite(M2B, LOW);
  }

  if(command == 1){ //  FORWARD
    digitalWrite(M1A, HIGH);
    digitalWrite(M2A, HIGH);
    delay(FORWARD_BACKWARD_DELAY);
    digitalWrite(M1A, LOW);
    digitalWrite(M2A, LOW);
  }

  if(command == 2){ //  BACKWARD
    digitalWrite(M1B, HIGH);
    digitalWrite(M2B, HIGH);
    delay(FORWARD_BACKWARD_DELAY);
    digitalWrite(M1B, LOW);
    digitalWrite(M2B, LOW);
  }

  if(command == 3){ //  LEFT
    digitalWrite(M1B, HIGH);
    digitalWrite(M2A, HIGH);
    delay(TURN_DELAY);
    digitalWrite(M1B, LOW);
    digitalWrite(M2A, LOW);
  }

  if(command == 4){ //  RIGHT
    digitalWrite(M1A, HIGH);
    digitalWrite(M2B, HIGH);
    delay(TURN_DELAY);
    digitalWrite(M1A, LOW);
    digitalWrite(M2B, LOW);
  }
}
