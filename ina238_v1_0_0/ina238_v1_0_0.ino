// Version 1.0.0
// Last Modified: 08-20-2025
// Code is a modified version of the example provided in
// the official Adafruit INA238 Git repository

#include <Adafruit_INA238.h>

Adafruit_INA238 ina238 = Adafruit_INA238();

void setup() {
  Serial.begin(115200);
  // Wait until serial port is opened
  while (!Serial) {
    delay(10);
  }
  
  Serial.println("Adafruit INA238 Test");

  if (!ina238.begin()) {
    Serial.println("Couldn't find INA238 chip");
    while (1)
      ;
  }
  Serial.println("Found INA238 chip");
  // set shunt resistance and max current
  ina238.setShunt(0.015, 10.0);

  ina238.setAveragingCount(INA2XX_COUNT_16);
  uint16_t counts[] = {1, 4, 16, 64, 128, 256, 512, 1024};
  Serial.print("Averaging counts: ");
  Serial.println(counts[ina238.getAveragingCount()]);

  // set the time over which to measure the current and bus voltage
  ina238.setVoltageConversionTime(INA2XX_TIME_150_us);
  ina238.setCurrentConversionTime(INA2XX_TIME_280_us);
}

// prints current, bus voltage, power, and temperature
void loop() {
  Serial.print("Current: ");
  Serial.print(ina238.getCurrent_mA());
  Serial.println(" mA");

  Serial.print("Bus Voltage: ");
  Serial.print(ina238.getBusVoltage_V());
  Serial.println(" V");

  Serial.print("Power: ");
  Serial.print(ina238.getPower_mW());
  Serial.println(" mW");

  Serial.print("Temperature: ");
  Serial.print(ina238.readDieTemp());
  Serial.println(" *C");

  Serial.println();
  delay(1000);
}
