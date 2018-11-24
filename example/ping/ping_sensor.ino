/* PING + ESP TO PY: SENSOR CODE
 * Written by Junicchi
 * https://github.com/Kebablord   
 * 
 * CODING THE PING SENSOR MODULE */
 
/* NOTE! This example is for Nodemcu or modules with more than 1 GPIO */
 
// DEFINING PING'S VARS AND NUMBERS
const int trigPin = 4; // D2 PIN
const int echoPin = 5; // D1 PIN
long duration;
int distance;

String sensor_code(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
// Read the returned wave
  duration = pulseIn(echoPin, HIGH);
// Calculate the delay into cm
  distance= duration*0.034/2;
// convert distance to String
  String final_data = String(distance);
// this is what sensor_code() returns when it's called
  return final_data;
  }
