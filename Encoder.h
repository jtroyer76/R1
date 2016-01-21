#ifndef ENCODER_H
#define ENCODER_H

#define LEFT_ENCODER_PIN 0
#define RIGHT_ENCODER_PIN 1

#define MAX_PULSE_WIDTH 160

extern volatile int LeftEncoder;
extern volatile int RightEncoder;

extern volatile unsigned long lastLeft;
extern volatile unsigned long lastRight;

void UpdateLeftEncoder();
void UpdateRightEncoder();

#endif
