#ifndef GY33_H
#define GY33_H

#include "Wire.h"
#include "Adafruit_TCS34725.h"

#define LED 13
#define SWITCH 14



 #define white 0
 #define green 1
 #define black 2
 #define gray 3
 #define  red 4
 #define notInterested 5



void GY33_Init(void);
void recalebrate_color();
char GY33_GetColor(void);


#endif
