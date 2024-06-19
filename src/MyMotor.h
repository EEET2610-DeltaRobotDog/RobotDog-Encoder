#include <Arduino.h>

#define MOT1_A 18 // MOT 1A
#define MOT1_B 17 // MOT 1B

#define MOT1_Channel 0 // MOT 1 channel

#define PWM_FREQ 10000 // PWM Frequency: 10kHz
#define PWM_RES 8      // PWM resolution 255

double MOT1_cmd = 0; // MOT1 command [-255; 255]

//============================================================
void Init_Motor()
{
    pinMode(MOT1_A, OUTPUT);
    pinMode(MOT1_B, OUTPUT);
    ledcSetup(MOT1_Channel, PWM_FREQ, PWM_RES);
}
//============================================================
void Send_PWM(int PINA, int PINB, double mot_cmd, int channel)
{
    // Reverse direction, if the mot_cmd is from [-255; 0]
    if (mot_cmd < 0)
    {
        ledcAttachPin(PINB, channel);
        ledcDetachPin(PINA);
        digitalWrite(PINA, LOW);
        ledcWrite(channel, abs(mot_cmd));
    }
    // Forward direction, if the mot_cmd is from [0; 255]; 
    else 
    {
        ledcAttachPin(PINA, channel);
        ledcDetachPin(PINB);
        digitalWrite(PINB, LOW);
        ledcWrite(channel, abs(mot_cmd));
    }
}

//============================================================
void Run_Motor()
{
    Send_PWM(MOT1_A, MOT1_B, MOT1_cmd, MOT1_Channel);
}
