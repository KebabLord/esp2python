#include "LOCAL_MINI.h"

/* MAP
 start(ssid,password)---> Starts the connection with given username and password
 waitUntilNewReq() -----> Waits until a request is received from python
 returnThis(data) ------> sends the sensor data to localhost 
*/

void setup(){
  Serial.begin(9600);
  start("ssid","password");

  /* SENSOR SETUP CODE HERE */
  
}

void loop(){
  waitUntilNewReq();

  /* SENSOR LOOP CODE HERE */

  returnThis(yoursensordata);
}
