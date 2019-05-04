/* PING -> ESP TO PY
 * Written by Junicchi
 * https://github.com/Kebablord 
 *
/* This example is written for Nodemcu Modules */

#include "ESP_MICRO.h" // importing our library

#define TRIG_PIN 4
#define ECHO_PIN 5
long duration;
int distance;

void setup(){
  Serial.begin(9600);
  start("USERNAME","PASSWORD");  // Wifi details connect to
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop(){
  waitUntilNewReq();  //Waits until a new request from python come
  
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
 // Read the returned wave
  duration = pulseIn(ECHO_PIN, HIGH);
 // Calculate the delay into cm
  distance = duration*0.034/2;

  returnThisInt(distance); //Returns the data to python
}
