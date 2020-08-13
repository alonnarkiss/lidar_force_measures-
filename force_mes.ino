
#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;
float distance_2;
float delta ;
float f;
void setup()
{
  Serial.begin(9600);
  Serial.println("VL523L0X laser distance test");
  Wire.begin();

  sensor.init();
  sensor.setTimeout(500);
  
  // Start continuous back-to-back mode (take readings as
  // fast as possible).  To use continuous timed mode
  // instead, provide a desired inter-measurement period in
  // ms (e.g. sensor.startContinuous(100)).
  sensor.startContinuous();
}

void loop()
{ 
  float distance = sensor.readRangeContinuousMillimeters();// make it in float 
  distance_2 = distance /1000; //div by 1K to get result in meter
  delta =0.12 - distance_2;
  f = delta *950; // delta X K (hook low)
  //Serial.print("distance = ");// print distance
  Serial.print("mg = ");// print distance
  Serial.print(f);// print force
  //Serial.println(f);
  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }

  Serial.println();
}
