#ifndef ALTRASONIC_H
#define ALTRASONIC_H

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 1 //attach pin D3 Arduino to pin Trig of HC-SR04

void AltraSonic_init();
int get_distance();

#endif
