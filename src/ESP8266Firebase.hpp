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

#pragma once

#ifndef esp8266firebase_hpp
#define esp8266firebase_hpp

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <string>

#define PORT 443

class Firebase {
public:
    void begin(String referenceURL, String apiKey, String authToken);
    void signIn(String email, String password);
    // void json(bool json);
    void setBufferSize(int recv, int xmit) {
        _recv = recv; _xmit = xmit;
    }

    int push(String path, String data);
    String get(String path);
    int set(String path, String data);
    int del(String path);

public:
    int setString(String path, String data);
    int setInt(String path, int data);
    int setFloat(String path, float data);
    int setBool(String path, bool data);
    int pushString(String path, String data);
    int pushInt(String path, int data);
    int pushFloat(String path, float data);
    int pushBool(String path, bool data);
    String getString(String path);
    int getInt(String path);
    float getFloat(String path);
    bool getBool(String path);

private:
    WiFiClientSecure _httpsClient;
    String _host, _apiKey;
    String _authToken, _String;
    // bool _json = false;
    bool _checkSignIn = false;
    int _int, _recv=1024, _xmit=1024;
    float _float;
    bool _bool;
    
private:
    void connect_to_host();
};

#endif