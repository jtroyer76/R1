#ifndef ENCODER_H
#define ENCODER_H

#define LEFT_ENCODER_PIN 0
#define RIGHT_ENCODER_PIN 1

extern volatile int LeftEncoder;
extern volatile int RightEncoder;

void UpdateLeftEncoder();
void UpdateRightEncoder();
void ResetEncoders();

#endif
