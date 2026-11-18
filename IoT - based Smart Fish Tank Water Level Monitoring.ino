#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

// WiFi Credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// KiwisIoT Topic ID
const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

// Water Level Sensor
#define WATER_SENSOR A0

// Calibration Values
const int DRY_VALUE = 100;
const int WET_VALUE = 800;

// Low Water Threshold
const int LOW_LEVEL = 20;

// KiwisIoT
KiwisIoT kiwisiot(ssid, pass, topic);

unsigned long lastSend = 0;

void setup() {

  Serial.begin(115200);

  pinMode(WATER_SENSOR, INPUT);

  kiwisiot.begin();

  Serial.println("Smart Fish Tank Monitoring Started");
}

void loop() {

  kiwisiot.run();

  if (millis() - lastSend >= 2000) {

    lastSend = millis();

    // Read Water Sensor
    int sensorValue = analogRead(WATER_SENSOR);

    // Calculate Water Level
    int waterLevel = map(
      sensorValue,
      DRY_VALUE,
      WET_VALUE,
      0,
      100
    );

    waterLevel = constrain(waterLevel, 0, 100);

    // Water Status
    String waterStatus;

    if (waterLevel < LOW_LEVEL) {
      waterStatus = "LOW WATER";
    }
    else {
      waterStatus = "NORMAL";
    }

    // Serial Monitor
    Serial.println("\n--- FISH TANK MONITOR ---");

    Serial.print("Raw Value: ");
    Serial.println(sensorValue);

    Serial.print("Water Level: ");
    Serial.print(waterLevel);
    Serial.println("%");

    Serial.print("Water Status: ");
    Serial.println(waterStatus);

    // Send Data to KiwisIoT
    kiwisiot.send("0", String(waterLevel));

    kiwisiot.send("1", waterStatus);
  }
}