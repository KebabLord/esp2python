
# ESP8266 & PYTHON FOR NOOBS
This project helps you to get any sensor data from esp8266 to python, as a variable.

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
I just over-simplified a complex code while compressing everything into 3 function. You have 'default.ino' as a template. Everything is so easy. You're just normally writing the sensor code as always, using this 3 function to send / control / return.

## start( ssid, pass)
You simply enter your wifi details into this function and it starts the connection, ssid is your wifi username, pass is your wifi password. In the default.ino, I put it in first line of `void setup()` so it esp can directly connect to internet when opened.

## waitUntilNewReq( )
 It's just a time block that waits for a request. It gives you the full control over python. With this: code is not running on his own, it'll wait a python request so it can check the sensor data or run.

## returnThis(  )
As finally, you can return the desired data (or simply sensor data) to localhost server, python will read whatever returned with returnThis(), you can also look into python code.

## String rule
We also have a string variable called `rule`, it's simply:
https://example.com/**thistext**

So you can use `rule` in your if statements or use it to rule the system.  **To summarize** you can interact the system 

    if (rule=="ledOneOpen"){
    digitalWrite(LED,HIGH);
    }

While uploading the code, open serial port. The localhost's IP will be printed in serialport when flashing is done and ESP is connected. Don't forget, localhosts IP changes by wifi to wifi, not session to session.
Finally define the URL variable in python code with localhost's IP, as an example: https://192.123.132

*Run or modify the code, you got the data now :3*

# Addition
 - The sensor data getting code *(aka. sensor_code function)* only runs when python sends a request.
- It takes only 0.5 seconds max totally (sending request & reading return) :3
 - The **main.ino** is fork of [mDNSserver example](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266mDNS) by [Ivan Grokhotkov](https://github.com/igrr) 

### Deficiencies
 - ~~The code is a bit complex, will be simplified.~~
 - Needs a tutorial video
