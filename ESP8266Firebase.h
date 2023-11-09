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

#ifndef ESP8266Firebase_h
	#define ESP8266Firebase_h
	#include "Arduino.h"

	#if defined(ESP8266)
		#include <ESP8266WiFi.h>
	#else
		#error "Please select an ESP8266 board for this sketch."
	#endif

	#define PORT 443

	class Firebase
	{
		public:
			Firebase(String referenceURL);
			int setString(String path, String data);
			int setNum(String path, String data);
			int setInt(String path, int data);
			int setFloat(String path, float data);
			int pushString(String path, String data);
			int pushNum(String path, String data);
			int pushInt(String path, int data);
			int pushFloat(String path, float data);
			void getData(String path);
			String getString(String path);
			int getInt(String path);
			float getFloat(String path);
			int deleteData(String path);
			void json(bool json);
			void Connect_to_host();

		private:
			String _host;
			bool _json = false;
			String _String;
			int _int;
			float _float;
			WiFiClientSecure _httpsClient;
	};
#endif
