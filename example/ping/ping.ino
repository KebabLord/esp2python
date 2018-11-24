/* PING + ESP TO PY: MAIN
 * Written by Junicchi
 * https://github.com/Kebablord 
 */

/* NOTE! This example is for Nodemcu or modules with more than 1 GPIO */

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiClient.h>

/* SET THE WIFI DETAILS CONNECT TO */
const char* ssid = "wifi_name";
const char* password = "password";
/* PORT */
WiFiServer server(80);

void setup(void) {
/* !SETTING THE GPIO PINS OF THE PING SENSOR!*/
  pinMode(4, OUTPUT); // D2 PIN
  pinMode(5, INPUT);  // D1 PIN
  
  Serial.begin(115200);

// Connect to wifi network
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password); 
  Serial.println("");
// Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
// Setting up mDNS responder
  if (!MDNS.begin("esp8266")) {
    Serial.println("Error setting up MDNS responder!");
    while (1) {
      delay(1000);
    }
  }
  Serial.println("mDNS responder started");
// Start TCP (HTTP) server
  server.begin();
  Serial.println("TCP server started");
// Add service to MDNS-SD
  MDNS.addService("http", "tcp", 9020);
}


void loop(void) {

// WAIT FOR THE REQUEST
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  Serial.println("");
  Serial.println("NEW REQUEST");
// Waiting client to connect
  while (client.connected() && !client.available()) {
    delay(1);
  }
// Read the first line of HTTP request
  String req = client.readStringUntil('\r');
  int addr_start = req.indexOf(' ');
  int addr_end = req.indexOf(' ', addr_start + 1);
  if (addr_start == -1 || addr_end == -1) {
    Serial.print("Invalid request: ");
    Serial.println(req);
    return;
  }
  req = req.substring(addr_start + 1, addr_end);
  Serial.print("Requested Path: ");
  Serial.println(req);
  client.flush();

/* _____ ______ _   _ _____ _____ _   _  _____ 
  / ____|  ____| \ | |  __ \_   _| \ | |/ ____|
 | (___ | |__  |  \| | |  | || | |  \| | |  __ 
  \___ \|  __| | . ` | |  | || | | . ` | | |_ |
  ____) | |____| |\  | |__| || |_| |\  | |__| |
 |_____/|______|_| \_|_____/_____|_| \_|\_____|
     CALLING THE FUNCTION & SENDING THE DATA   */

  String s;

  if (req == "/") {
    IPAddress ip = WiFi.localIP();
    String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);

    s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n ";
    String our_data = sensor_code();
    //Finally we added our data to protocol code.
    s += our_data;
    Serial.println("Sending 200");
  }
      
client.print(s); //SEND :3
Serial.println("Done with client");
}
