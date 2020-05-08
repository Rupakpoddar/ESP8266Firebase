#include <ESP8266WiFi.h>
//#include <WiFiClientSecure.h> 
//#include <ESP8266WebServer.h>
//#include <ESP8266HTTPClient.h>
#include "ESP8266Firebase.h"

Firebase::Firebase(String projectID) : Firebase::Firebase(projectID, DEFAULT_FIREBASE_FINGERPRINT){}

Firebase::Firebase(String projectID, const char* FIREBASE_FINGERPRINT){
	_host = projectID+".firebaseio.com";
	_FIREBASE_FINGERPRINT = FIREBASE_FINGERPRINT;
}

String Firebase::setString(String link, String data){
  WiFiClientSecure httpsClient;
 
  httpsClient.setFingerprint(_FIREBASE_FINGERPRINT);
  httpsClient.setTimeout(15000);
  
  int r=0;
  while((!httpsClient.connect(_host, _httpsPort)) && (r < 30)){
      delay(100);
      r++;
  }
  
  String Link = String("/")+link+String(".json");

  String msg = "\""+data+"\"";
  
  httpsClient.print(String("PUT ") + Link + " HTTP/1.1\r\n" +
          "Host: " + _host + "\r\n" +
          "Connection: close\r\n" +
          "Accept: */*\r\n" +
          "User-Agent: Mozilla/4.0 (compatible; esp8266 Lua; Windows NT 5.1)\r\n" +
          "Content-Type: application/json;charset=utf-8\r\n" +
          "Content-Length: "+msg.length()+"\r\n" +
          "\r\n" + 
          msg + "\r\n");
                   
  while (httpsClient.connected()) {
    String line = httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }
 
  String line;
  while(httpsClient.available()){        
    line = httpsClient.readStringUntil('\n');
    return line; //return this
  }
}

String Firebase::setInt(String link, int data){
  String Data = String(data);
  return Firebase::setNum(link, Data);
}

String Firebase::setFloat(String link, float data){
  String Data = String(data);
  return Firebase::setNum(link, Data);
}

String Firebase::setNum(String link, String msg){
  WiFiClientSecure httpsClient;
 
  httpsClient.setFingerprint(_FIREBASE_FINGERPRINT);
  httpsClient.setTimeout(15000);
  
  int r=0;
  while((!httpsClient.connect(_host, _httpsPort)) && (r < 30)){
      delay(100);
      r++;
  }
  
  String Link = String("/")+link+String(".json");
  
  httpsClient.print(String("PUT ") + Link + " HTTP/1.1\r\n" +
          "Host: " + _host + "\r\n" +
          "Connection: close\r\n" +
          "Accept: */*\r\n" +
          "User-Agent: Mozilla/4.0 (compatible; esp8266 Lua; Windows NT 5.1)\r\n" +
          "Content-Type: application/json;charset=utf-8\r\n" +
          "Content-Length: "+msg.length()+"\r\n" +
          "\r\n" + 
          msg + "\r\n");
                   
  while (httpsClient.connected()) {
    String line = httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }
 
  String line;
  while(httpsClient.available()){        
    line = httpsClient.readStringUntil('\n');
    return line; //return this
  }
}

String Firebase::pushString(String link, String data){
  WiFiClientSecure httpsClient;
 
  httpsClient.setFingerprint(_FIREBASE_FINGERPRINT);
  httpsClient.setTimeout(15000);
  
  int r=0;
  while((!httpsClient.connect(_host, _httpsPort)) && (r < 30)){
      delay(100);
      r++;
  }
  
  String Link = String("/")+link+String(".json");

  String msg = "\""+data+"\"";
  
  httpsClient.print(String("POST ") + Link + " HTTP/1.1\r\n" +
          "Host: " + _host + "\r\n" +
          "Connection: close\r\n" +
          "Accept: */*\r\n" +
          "User-Agent: Mozilla/4.0 (compatible; esp8266 Lua; Windows NT 5.1)\r\n" +
          "Content-Type: application/json;charset=utf-8\r\n" +
          "Content-Length: "+msg.length()+"\r\n" +
          "\r\n" + 
          msg + "\r\n");
                   
  while (httpsClient.connected()) {
    String line = httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }
 
  String line;
  while(httpsClient.available()){        
    line = httpsClient.readStringUntil('\n');
    return line; //return this
  }
}

String Firebase::pushInt(String link, int data){
  String Data = String(data);
  return Firebase::pushNum(link, Data);
}

String Firebase::pushFloat(String link, float data){
  String Data = String(data);
  return Firebase::pushNum(link, Data);
}

String Firebase::pushNum(String link, String msg){
  WiFiClientSecure httpsClient;
 
  httpsClient.setFingerprint(_FIREBASE_FINGERPRINT);
  httpsClient.setTimeout(15000);
  
  int r=0;
  while((!httpsClient.connect(_host, _httpsPort)) && (r < 30)){
      delay(100);
      r++;
  }
  
  String Link = String("/")+link+String(".json");
  
  httpsClient.print(String("POST ") + Link + " HTTP/1.1\r\n" +
          "Host: " + _host + "\r\n" +
          "Connection: close\r\n" +
          "Accept: */*\r\n" +
          "User-Agent: Mozilla/4.0 (compatible; esp8266 Lua; Windows NT 5.1)\r\n" +
          "Content-Type: application/json;charset=utf-8\r\n" +
          "Content-Length: "+msg.length()+"\r\n" +
          "\r\n" + 
          msg + "\r\n");
                   
  while (httpsClient.connected()) {
    String line = httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }
 
  String line;
  while(httpsClient.available()){        
    line = httpsClient.readStringUntil('\n');
    return line; //return this
  }
}

String Firebase::getString(String link){
  Firebase::getData(link);
  return _String;
}

int Firebase::getInt(String link){
  Firebase::getData(link);
  return _int;
}

float Firebase::getFloat(String link){
  Firebase::getData(link);
  return _float;
}

void Firebase::getData(String link){
  WiFiClientSecure httpsClient;
 
  httpsClient.setFingerprint(_FIREBASE_FINGERPRINT);
  httpsClient.setTimeout(15000);
  
  int r=0;
  while((!httpsClient.connect(_host, _httpsPort)) && (r < 30)){
      delay(100);
      r++;
  }
  
  String Link = String("/")+link+String(".json");
  
  httpsClient.print(String("GET ") + Link + " HTTP/1.1\r\n" +
               "Host: " + _host + "\r\n" +               
               "Connection: close\r\n\r\n");

                   
  while (httpsClient.connected()) {
    String line = httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }
 
  String line;
  while(httpsClient.available()){        
    line = httpsClient.readStringUntil('\n');
    _int = line.toInt();
    _float = line.toFloat();
    if (_json == false){
      _String = line.substring(1,line.length()-1);
    }
    else{
      _String = line;
    }
  }
}

String Firebase::deleteData(String link){
  WiFiClientSecure httpsClient;
 
  httpsClient.setFingerprint(_FIREBASE_FINGERPRINT);
  httpsClient.setTimeout(15000);
  
  int r=0;
  while((!httpsClient.connect(_host, _httpsPort)) && (r < 30)){
      delay(100);
      r++;
  }
  
  String Link = String("/")+link+String(".json");
  
  httpsClient.print(String("DELETE ") + Link + " HTTP/1.1\r\n" +
               "Host: " + _host + "\r\n" +               
               "Connection: close\r\n\r\n");
                   
  while (httpsClient.connected()) {
    String line = httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }
 
  String line;
  while(httpsClient.available()){        
    line = httpsClient.readStringUntil('\n');
    return line; //return this
  }
}

void Firebase::json(bool json){
  _json = json;
}