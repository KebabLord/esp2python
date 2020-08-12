/* BASIC_TEST FOR ESP2PY
 * Written by Junicchi
 * https://github.com/Kebablord 
 *
 * It simply returns the variable "index" to python and
   increases it everytime a python request came
 */

#include "ESP_MICRO.h" 

int index = 0;

void setup(){
  Serial.begin(9600);
  start("WIFI SSID","PASSWORD");// Connect to wifi, enter your details here
}

void loop(){
  waitUntilNewReq();		// Waits until a new request from python come
  indeks += 1;
  returnThisInt(indeks);        // Returns the data to python
}
