#ifndef GY31_H
#define GY31_H

#define S0 4
#define S1 7
#define S2 8
#define S3 12
#define sensorOut 13



 #define white 0
 #define green 1
 #define black 2
 #define gray 3
 #define  red 4
 #define notInterested 5


void GY31_Init(void);
//void recalebrate_color();
char GY31_GetColor(void);


#endif
