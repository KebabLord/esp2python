
# ESP8266 & PYTHON FOR NOOBS
This project helps you to get any sensor data from esp8266 to python, as a variable. And python command to Esp

# Theory
Our esp connects to wifi and creates a localhost. Everytime our python sends a request to that localhost, our module runs the code and gets the instant sensor data, then publishes it to localhost as an HTML page. Finally python reads that data on the html localhost page and decodes it to integer or list (if the output is more than one).

# Requirements
Python lib:
 - urllib.request *(mostly internal)*

Arduino lib:
- [esp8266 card library](https://arduino-esp8266.readthedocs.io/en/2.4.1/installing.html) 

## System diagram
![diagram](diagram1.png)  
[Different visual version if you didn't understand.](diagram2.png)

# How to code
I just over-simplified a complex code while compressing everything into 3 function. 
You have to copy `ESP_MICRO.h` to your coding folder. And import it using `#include "ESP_MICRO.h"` on main code. Everything is so easy. You just normally programming as always, and using this 3 function to send / control / return.

## start( ssid, pass)
You simply enter your wifi details into this function and it starts the connection, ssid is your wifi username, pass is your wifi password. In the default.ino, I put it in first line of `void setup()` so it esp can directly connect to internet when opened.

## waitUntilNewReq( )
 It's just a time block that waits for a request. It gives you the full control over python. With this: code is not running on his own, it'll wait a python request so it can check the sensor data or run.

## returnThisStr(  )   & returnThisInt( )
As finally, you can return the desired data (or simply sensor data) to localhost server.
You can use returnThisInt() if you gonna return an integer, or returnThisStr() if a string

## getPath()
We also have a string returning function called `getPath()`, path is simply:
https://example.com/this --> "/this"

So you can use it in your if statements or use it to rule the system.  I mean you can interact and control a system 

    if (getPath()=="/OPEN_LED"){
    digitalWrite(LED,HIGH);
    }

# Important (Learning ESP's IP adress)
While uploading the code, open serial port. ESP's local IP will be printed in serialport when flashing is done and ESP is connected to
your wifi. Don't forget, localhosts IP changes by wifi to wifi, not session to session.
You'll need this when reading the data with python, an example: https://192.123.132

*Run or modify the code, you got the data now :3*

# Addition
- It takes only 0.5 seconds max totally (sending request & reading return), shit is fassssst
 - It's fork of [mDNSserver example](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266mDNS) by [Ivan Grokhotkov](https://github.com/igrr) 

### Deficiencies
 - ~~The code is a bit complex, will be simplified.~~
 - Needs a tutorial video
