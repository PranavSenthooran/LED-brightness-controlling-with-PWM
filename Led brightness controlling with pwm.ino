#define BLYNK_TEMPLATE_ID "TMPL3GHS31Lg3"
#define BLYNK_TEMPLATE_NAME "LED Brightness"
#define BLYNK_AUTH_TOKEN "AeqvJNdReifp6KWlKaBAEPJ5vxTHCcCS"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "dharun";
char pass[] = "123456677";
BlynkTimer timer;

// Set the motor driver pins
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;
int LED = 15;


void setup() {
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(LED, ledChannel);
  // Initialize Blynk
  Blynk.begin(auth, ssid, pass);
  }

void loop(){
  Blynk.run();
  timer.run();
}
BLYNK_WRITE(V0) {
  int data = param.asInt();
  int pwmWave = map(data,  0, 4095, 0, 255);
  ledcWrite(ledChannel, pwmWave);}
