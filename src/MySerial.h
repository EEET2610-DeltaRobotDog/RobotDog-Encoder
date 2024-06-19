#include <Arduino.h>

unsigned long Serial_time = 0; // time in us
// ====================================================================================
void Init_Serial()
{
  Serial.begin(115200);
  while (!Serial)
    ;
}
// ====================================================================================
void SerialDataPrint()
{
  if (micros() - Serial_time >= 10000)
  {
    Serial_time = micros();
    Serial.println(Serial_time / 10000);
    Serial.print(">MOT1_cmd:");
    Serial.println(MOT1_cmd);
    Serial.print(">cnt1:");
    Serial.println(cnt1);
    Serial.print(">th1:");
    Serial.println(th1);
  }
}
// ====================================================================================
void SerialDataWrite()
{
  static String received_chars;
  while (Serial.available())
  {
    char inChar = (char)Serial.read();
    received_chars += inChar;
    if (inChar == '\n')
    {
      switch (received_chars[0])  
      {
      case 'q':
        received_chars.remove(0, 1);
        MOT1_cmd = received_chars.toFloat();
        break;
      default:
        break;
      }
      received_chars = "";
    }
  }
}