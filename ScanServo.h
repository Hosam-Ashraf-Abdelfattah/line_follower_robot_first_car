#ifndef SCANSERVO_H
#define SCANSERVO_H

  #include <Servo.h>
  Servo altrasonic_scan;
  #define ALTRASONIC_SERVO_PIN 11
  void Servo_init();
  void Servo_altrasonic_scan_set_position(unsigned char);
  unsigned char Servo_altrasonic_scan_get_position();
  
#endif
