# ESP8266 TO PYTHON
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
[More visual version if you didn't understand.](diagram2.png)

# How to code
We have two **arduino ide** project files in our main folder. The **sensor.ino** is for accessing data on the sensor. Your code simply goes in `sensor_code()` function, use it like it's `void loop()` .  It must get the instant data and return it as a string so we can call it in  **main.ino**  and send it to localserver. things that normally goes on `void setup()` still goes to `void setup()` on the **main.ino**. But define your variables that you'll use in sensor_code in **sensor.ino**.

The **main.ino** is where we connect to wifi, create the localhost, run the function we defined in `sensor.ino` and send it to localhost. You have to configure wifi settings in it to make module be able to connect to wifi. After everything is done your sketches are ready, upload them. Arduino IDE will compile both of two files into one sketch when flashing. While flashing; open serialport at 115200, and wait for the sketch to be uploaded, it'll print you the IP of the localserver, we need it for our python code.  After that, in python code, enter your localhost and simply run it. **To summarize;**

 1. Write your code to read sensor data in the function `sensor_code()` in **sensor.ino**  `python`
 2. Configure your wifi settings connect to, in **main.ino**
3.  While uploading the code, open serial port. The localhost's IP will be posted when flashing is done, localhosts IP changes by wifi to wifi, not session to session.
4. Define the URL variable in python code with localhost's IP, as an example: https://192.123.132
5. Run or modify the code, you got the data now :3

# Addition
 - The sensor data getting code *(aka. sensor_code function)* only runs when python sends a request.
- It takes only 0.5 seconds max totally (sending request & reading return) :3
- **main.ino** and **sensor.ino** must be in same "main" folder so arduino ide can compile both of them into one.
 - The **main.ino** is fork of [mDNSserver example](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266mDNS) by [Ivan Grokhotkov](https://github.com/igrr) 

### Deficiencies
 - The code is a bit complex, will be simplified.
 - Needs a tutorial video