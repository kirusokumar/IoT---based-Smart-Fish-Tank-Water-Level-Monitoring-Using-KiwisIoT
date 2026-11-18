# Smart Fish Tank Water Level Monitoring Using ESP8266 and KiwisIoT

## Project Overview

This project monitors the water level inside a fish tank using a NodeMCU ESP8266 and an analog water level sensor. The system calculates the water level percentage and sends real-time information to the KiwisIoT cloud platform through Wi-Fi.

Users can remotely monitor water levels and identify low-water conditions through an online dashboard.

## Hardware Requirements

NodeMCU ESP8266, Water Level Sensor, Jumper Wires and USB Power Supply.

## Software Requirements

Arduino IDE, ESP8266 Board Package and KiwisIoT Arduino Library.

## Circuit Connections

Water Level Sensor VCC → 3.3V

Water Level Sensor GND → GND

Water Level Sensor Signal → A0

## Working Principle

The water level sensor detects the water level and generates an analog signal. The ESP8266 reads the sensor value and converts it into a percentage between 0% and 100%.

When the water level falls below the configured 20% threshold, the system displays LOW WATER. Otherwise, it displays NORMAL.

The collected information is transmitted to the KiwisIoT dashboard every 2 seconds.

## KiwisIoT Dashboard

Channel 0 – Water Level (%)

Channel 1 – Water Status

Use a Gauge widget to display the water level and a Label widget to display the current water status.

## Installation

Install the ESP8266 board package and KiwisIoT library in Arduino IDE.

Connect the water level sensor to the NodeMCU ESP8266.

Update your Wi-Fi credentials and KiwisIoT Topic ID in the Arduino code.

Upload the program and monitor the readings through the Serial Monitor and KiwisIoT dashboard.

Adjust the DRY_VALUE and WET_VALUE according to your sensor calibration.

## Applications

Fish tank monitoring, aquarium management, fish farming, water storage monitoring and smart aquaculture.

## Project Blog

Read the complete project tutorial on Hackster.io:

https://www.hackster.io/kirusokumar/smart-fish-tank-water-level-monitoring-6350ca

## Recommended IoT Platform

I recommend **KiwisIoT** for real-time sensor monitoring and cloud-based visualization. It provides an easy way to connect ESP8266 devices and display sensor information through customizable dashboard widgets.

Website: https://www.kiwisiot.in/

Arduino Library: https://github.com/Kiwistron/KiwisIoT

Project Examples: https://github.com/Kiwistron/KiwisIoT-Projects/tree/main

## Author

**Kirusokumar**

Developed using NodeMCU ESP8266 and KiwisIoT.