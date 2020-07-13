# ESP8266Firebase
## Arduino library to read and write data to Google Firebase.
## [UPDATE 13 JULY 2020]: Now faster than ever before! Almost instant updating/response speed.

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
