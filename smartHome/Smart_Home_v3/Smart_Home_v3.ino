
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Servo.h>

ESP8266WebServer server;
uint8_t pin_led = 16;
char* ssid = "BYOD";
char* password = "";

Servo servoMain;

int mode = 0;


void setup()
{
  pinMode(pin_led, OUTPUT);
  WiFi.begin(ssid,password);
  Serial.begin(115200);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/",[](){server.send(200,"text/plain",String(mode));});
  server.on("/off",toggleOFF);
  server.on("/on",toggleON);
  server.begin();
}

void loop()
{
  server.handleClient();
}

void toggleLED()
{
  digitalWrite(pin_led,!digitalRead(pin_led));
  server.send(204,"");
}

void toggleOFF() {
  if (mode == 1) {
  servoMain.attach(2);
  delay(50);   
  digitalWrite(pin_led,!digitalRead(pin_led));
    servoMain.write(0);   // Turn Servo Left to 0 degrees
   delay(200);          // Wait 1 second
   servoMain.write(90);  // Turn Servo back to center position (90 degrees)
   delay(10);
   servoMain.write(180);
   delay(140);
   servoMain.write(90);  // Turn Servo back to center position (90 degrees)
   delay(10);
   servoMain.detach();
   mode = 0;
   server.send(204,"");
 }
 
}

void toggleON(){
  
   if (mode == 0) {
   servoMain.attach(2);
   delay(50);   
   servoMain.write(180);   // Turn Servo Left to 0 degrees
   delay(200);          // Wait 1 second
   servoMain.write(90);  // Turn Servo back to center position (90 degrees)
   delay(10);
   servoMain.write(0);
   delay(140);
   servoMain.write(90);  // Turn Servo back to center position (90 degrees)
   delay(10);
   mode = 1;
   servoMain.detach();  
   server.send(204,"");
   }
   
}

