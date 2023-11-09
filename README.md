# ESP8266Firebase
## Arduino library to read and write data to Google Firebase.
## [UPDATE Nov 2023]: Now faster than ever before! Almost instantaneous update and response speed.

# Tutorial
### The following steps are one-time process:

Step 1: Open your firebase project, select 'Database' and click 'View' under Realtime Database. 

![Step1](https://github.com/Rupakpoddar/ESP8266Firebase/blob/master/documentation/tutorial_1.png) 

Step 2: Select 'Rules'. 

![Step2](https://github.com/Rupakpoddar/ESP8266Firebase/blob/master/documentation/tutorial_2.png) 

Step 3: Change the '.read' and '.write' rules to 'true' and hit enter. 

![Step3.1](https://github.com/Rupakpoddar/ESP8266Firebase/blob/master/documentation/tutorial_3.png) 

![Step3.2](https://github.com/Rupakpoddar/ESP8266Firebase/blob/master/documentation/tutorial_4.png) 

Step 4: Select 'Publish'. 

![Step4](https://github.com/Rupakpoddar/ESP8266Firebase/blob/master/documentation/tutorial_5.png) 

Step 5: Go back to the 'Data' tab. Copy the reference url, and paste it in the Arduino code. 

![Step5](https://github.com/Rupakpoddar/ESP8266Firebase/blob/master/documentation/tutorial_6.png) 

That is it. You are all set! You can go through the example codes to get familiar with the library. 
