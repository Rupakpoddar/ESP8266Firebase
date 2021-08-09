# ESP8266Firebase
## Arduino library to read and write data to Google Firebase Realtime Database.
## [UPDATE JULY 2021]: Now faster than ever before! Optimised for low latency performance. Added option to completely avoid entering fingerprint.

## Official Arduino Link:
### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;https://www.arduino.cc/reference/en/libraries/esp8266-firebase/

## YouTube Videos: 
### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;https://www.youtube.com/watch?v=NqKaHee_zQA
### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;https://www.youtube.com/watch?v=cIa5vQ7rRa0
### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;https://www.youtube.com/watch?v=xpZ0oMvpQ3g

# Tutorial
### The following steps are one-time process:

Step 1: Open your firebase project, select 'Database' and click "View" under Realtime Database.

![Step1](https://github.com/Rupakpoddar/ESP8266Firebase/blob/master/documentation/tutorial_1.png)

Step 2: Select "Rules".

![Step2](https://github.com/Rupakpoddar/ESP8266Firebase/blob/master/documentation/tutorial_2.png)

Step 3: Change the ".read" and ".write" rules to 'true' and hit enter.

![Step3.1](https://github.com/Rupakpoddar/ESP8266Firebase/blob/master/documentation/tutorial_3.png)

![Step3.2](https://github.com/Rupakpoddar/ESP8266Firebase/blob/master/documentation/tutorial_4.png)

Step 4: Select 'Publish'.

![Step4](https://github.com/Rupakpoddar/ESP8266Firebase/blob/master/documentation/tutorial_5.png)

Step 5: Click the gear icon and select "Project settings".

![Step5](https://github.com/Rupakpoddar/ESP8266Firebase/blob/master/documentation/tutorial_6.png)

Step 6: In the settings page, you will find a unique 'Project ID'. Copy the project ID and paste it in the Arduino code. You can go through the example codes to get familiar with the library.

![Step6](https://github.com/Rupakpoddar/ESP8266Firebase/blob/master/documentation/tutorial_7.png)
