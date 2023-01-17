
// Include the library files
#define BLYNK_TEMPLATE_ID "TMPLM1qNilEr"
#define BLYNK_DEVICE_NAME "RCproject"
#define BLYNK_AUTH_TOKEN "mJdRmqmvRchmTygEADCRWWWE7rsbnDad"
#include <DHT.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define VP_X V0
#define VP_Y V1

#define DHTPIN D2 //Connect Out pin to D2 in NODE MCU
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);

char auth[] = "mJdRmqmvRchmTygEADCRWWWE7rsbnDad"; //Enter your Blynk auth token
char ssid[] = "DIGI-p3MJ";
char pass[] = "yPYj2PTyWy";
int x,y;

// Get the joystick values
BLYNK_WRITE(VP_X) {
  x = param[0].asInt();
  //Blynk.virtualWrite(VP_X, x);
}
// Get the joystick values
BLYNK_WRITE(VP_Y) {
  y = param[0].asInt();
  //Blynk.virtualWrite(VP_Y, y);
}

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
    Blynk.virtualWrite(V3, t);
    Blynk.virtualWrite(V5, h);
   
}

//Get the slider values
/*BLYNK_WRITE(VP_SPEED) {
  Speed = param.asInt();
}*/
void setup() {
     Serial.begin(115200);
     Blynk.begin(auth, ssid, pass);

   }

void loop(){
  Blynk.run();// Run the blynk function
  //sendSensor();
   /*Serial.print("X: ");
   Serial.println(x);
   Serial.print("Y: ");
   Serial.println(y);*/
   Serial.write((byte)x);
   Serial.write((byte)y);
 
  }
