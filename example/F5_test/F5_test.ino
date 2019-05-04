/* F5 TEST FOR ESP2PY
 * Written by Junicchi
 * https://github.com/Kebablord 
 *
 * It simply increases and returns index var everytime a python req came */

#include "ESP_MICRO.h" 

int indeks = 0;

void setup(){
  Serial.begin(9600);
  start("USERNAME","PASSWORD");  // Wifi details connect to
}

void loop(){
  waitUntilNewReq();  //Waits until a new request from python come

  /* increases index when a new request came*/
  indeks += 1;

  returnThisInt(indeks); //Returns the data to python
}
