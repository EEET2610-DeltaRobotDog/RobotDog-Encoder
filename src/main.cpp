#include <Arduino.h>
#include "MyMotor.h"
#include "MyEncoder.h"
#include "MySerial.h"

void setup()
{
  Init_Motor();
  Init_Encoder();
  Init_Serial();
}

void loop()
{
  Run_Motor();
  Get_Angle();
  SerialDataPrint();
  SerialDataWrite();
}
