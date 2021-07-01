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

#include "ESP8266Firebase.h"

Firebase::Firebase(String projectID){
	_host = projectID+".firebaseio.com";
	_httpsClient.setInsecure();
}

Firebase::Firebase(String projectID, const char* FIREBASE_FINGERPRINT){
	_host = projectID+".firebaseio.com";
	_httpsClient.setFingerprint(FIREBASE_FINGERPRINT);
	_httpsClient.setTimeout(1000);
}

String Firebase::setString(String link, String data){
	Connect_to_host();
  String Link = String("/")+link+String(".json");
  String msg = "\""+data+"\"";

  _httpsClient.print(String("PUT ") + Link + " HTTP/1.1\r\n" +
          "Host: " + _host + "\r\n" +
          "Connection: close\r\n" +
          "Accept: */*\r\n" +
          "User-Agent: Mozilla/4.0 (compatible; esp8266 Lua; Windows NT 5.1)\r\n" +
          "Content-Type: application/json;charset=utf-8\r\n" +
          "Content-Length: "+msg.length()+"\r\n" +
          "\r\n" +
          msg + "\r\n");

  while (_httpsClient.connected()) {
    String line = _httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }

  String line;
  while(_httpsClient.available()){
    line = _httpsClient.readStringUntil('\n');
    return line; // Return this
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
	Connect_to_host();
  String Link = String("/")+link+String(".json");

  _httpsClient.print(String("PUT ") + Link + " HTTP/1.1\r\n" +
          "Host: " + _host + "\r\n" +
          "Connection: close\r\n" +
          "Accept: */*\r\n" +
          "User-Agent: Mozilla/4.0 (compatible; esp8266 Lua; Windows NT 5.1)\r\n" +
          "Content-Type: application/json;charset=utf-8\r\n" +
          "Content-Length: "+msg.length()+"\r\n" +
          "\r\n" +
          msg + "\r\n");

  while (_httpsClient.connected()) {
    String line = _httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }

  String line;
  while(_httpsClient.available()){
    line = _httpsClient.readStringUntil('\n');
    return line; // Return this
  }
}

String Firebase::pushString(String link, String data){
	Connect_to_host();
  String Link = String("/")+link+String(".json");

  String msg = "\""+data+"\"";

  _httpsClient.print(String("POST ") + Link + " HTTP/1.1\r\n" +
          "Host: " + _host + "\r\n" +
          "Connection: close\r\n" +
          "Accept: */*\r\n" +
          "User-Agent: Mozilla/4.0 (compatible; esp8266 Lua; Windows NT 5.1)\r\n" +
          "Content-Type: application/json;charset=utf-8\r\n" +
          "Content-Length: "+msg.length()+"\r\n" +
          "\r\n" +
          msg + "\r\n");

  while (_httpsClient.connected()) {
    String line = _httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }

  String line;
  while(_httpsClient.available()){
    line = _httpsClient.readStringUntil('\n');
    return line; // Return this
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
	Connect_to_host();
  String Link = String("/")+link+String(".json");

  _httpsClient.print(String("POST ") + Link + " HTTP/1.1\r\n" +
          "Host: " + _host + "\r\n" +
          "Connection: close\r\n" +
          "Accept: */*\r\n" +
          "User-Agent: Mozilla/4.0 (compatible; esp8266 Lua; Windows NT 5.1)\r\n" +
          "Content-Type: application/json;charset=utf-8\r\n" +
          "Content-Length: "+msg.length()+"\r\n" +
          "\r\n" +
          msg + "\r\n");

  while (_httpsClient.connected()) {
    String line = _httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }

  String line;
  while(_httpsClient.available()){
    line = _httpsClient.readStringUntil('\n');
    return line; // Return this
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
	Connect_to_host();
  String Link = String("/")+link+String(".json");

  _httpsClient.print(String("GET ") + Link + " HTTP/1.1\r\n" +
               "Host: " + _host + "\r\n" +
               "Connection: close\r\n\r\n");


  while (_httpsClient.connected()) {
    String line = _httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }

  String line;
  while(_httpsClient.available()){
    line = _httpsClient.readStringUntil('\n');
    _int = line.toInt();
    _float = line.toFloat();
    if (_json == false)
      _String = line.substring(1,line.length()-1);
    else
      _String = line;
  }
}

String Firebase::deleteData(String link){
	Connect_to_host();
  String Link = String("/")+link+String(".json");

  _httpsClient.print(String("DELETE ") + Link + " HTTP/1.1\r\n" +
               "Host: " + _host + "\r\n" +
               "Connection: close\r\n\r\n");

  while (_httpsClient.connected()) {
    String line = _httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }

  String line;
  while(_httpsClient.available()){
    line = _httpsClient.readStringUntil('\n');
    return line; // Return this
  }
}

void Firebase::json(bool json){
  _json = json;
}

void Firebase::Connect_to_host(){
	int r=0;
  while((!_httpsClient.connect(_host, PORT)) && (r < 30)){
      delay(100);
      r++;
  }
}
