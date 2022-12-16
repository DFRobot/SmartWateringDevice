/*!
 * @file wateringdevice.ino
 * @brief Green plant watering device
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @author Pai Da Xing
 * @version  V1.0
 * @date  2022-12-08
 * @url 
 */
#define BLYNK_TEMPLATE_ID           "TMPLxxxxxx"
#define BLYNK_DEVICE_NAME           "Device"
#define BLYNK_AUTH_TOKEN            "YourAuthToken"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

BlynkTimer timer;

int inPin = D7;
int modePin = D9;
int Control = D12;

const int AirValue = 4000;  
const int WaterValue = 0;   
int intervals = (AirValue - WaterValue) / 3;
int soilMoistureValue,humidity,humiditys = 0;  
bool condition = false;

//Send soil moisture value to virtual pin (V6) every second
void myTimerEvent() {
  Blynk.virtualWrite(V6, humiditys);
  // Blynk.virtualWrite(V2, "www");
  if (digitalRead(inPin) == 0 && !condition) {
  Blynk.virtualWrite(V3, "Water shortage");
  condition=true;
  }
   if (digitalRead(inPin) == 1) {
   condition = false;
  }
  //Blynk.logEvent("12");
}

//Detection of soil moisture
void Soilmoisture() {
  soilMoistureValue = analogRead(A0);  
  humidity = map(soilMoistureValue, WaterValue, AirValue, 0, 100);
  humiditys = 100 - humidity;
  Serial.print("soil moisture： ");
  Serial.print(humiditys);
  Serial.print(" %");
  
  
  if (soilMoistureValue > WaterValue && soilMoistureValue < (WaterValue + intervals)) {
    Serial.println("——Very Wet");
    digitalWrite(Control, LOW);
  } else if (soilMoistureValue > (WaterValue + intervals) && soilMoistureValue < (AirValue - intervals)) {
    Serial.println("——Wet");
    digitalWrite(Control, LOW);
  } else if (soilMoistureValue < AirValue && soilMoistureValue > (AirValue - intervals)) {
    Serial.println("——Dry");
    digitalWrite(Control, HIGH);
  }
  delay(100);
}


void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);  // Setup a function to be called every second
  pinMode(inPin, INPUT);
  pinMode(modePin, OUTPUT);
  pinMode(Control, OUTPUT);
  digitalWrite(modePin, HIGH);
  digitalWrite(Control, LOW);
}

void loop() {
  Blynk.run();
  timer.run();  // Initiates BlynkTimer
  Soilmoisture();
}
