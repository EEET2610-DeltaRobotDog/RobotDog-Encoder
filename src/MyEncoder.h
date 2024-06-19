#include <Arduino.h>

#define ENC1_A 4    // MOT 1A
#define ENC1_B 16   // MOT 1B
#define ENC_RES 330 // Encoder resolution*Gearbox ratio: 11*30

volatile long int cnt1 = 0; // Volatile as it changed during interrupt
double th1 = 0;             // Position angle in degrees

//================================================================================
void readEncoder1()
{
    int b = digitalRead(ENC1_B);
    cnt1 = (b > 0) ? (cnt1 + 1) : (cnt1 - 1);
}

void Init_Encoder()
{
    pinMode(ENC1_A, INPUT);
    pinMode(ENC1_B, INPUT);
    attachInterrupt(digitalPinToInterrupt(ENC1_A), readEncoder1, RISING);
}

void Get_Angle()
{
    th1 = cnt1 * 360 / ENC_RES; // Conversion between encoder count and degree
}