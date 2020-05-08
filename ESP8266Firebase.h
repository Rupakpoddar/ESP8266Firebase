#ifndef ESP8266Firebase_h
#define ESP8266Firebase_h

#include "Arduino.h"

#define DEFAULT_FIREBASE_FINGERPRINT "03 D6 42 23 03 D1 0C 06 73 F7 E2 BD 29 47 13 C3 22 71 37 1B"

class Firebase
{
	public:
		Firebase(String projectID);
		Firebase(String projectID, const char* FIREBASE_FINGERPRINT);

		String setString(String link, String data);
		
		String setNum(String link, String data);
		String setInt(String link, int data);
		String setFloat(String link, float data);

		String pushString(String link, String data);

		String pushNum(String link, String data);
		String pushInt(String link, int data);
		String pushFloat(String link, float data);

		void getData(String link);
		String getString(String link);
		int getInt(String link);
		float getFloat(String link);

		String deleteData(String link);

		void json(bool json);

	private:
		String _host;
		const char* _FIREBASE_FINGERPRINT;
		bool _json = false;
		const int _httpsPort = 443;
		String _String;
		int _int;
		float _float;
	
};

#endif