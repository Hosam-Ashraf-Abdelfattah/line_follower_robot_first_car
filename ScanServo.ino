 #include "ScanServo.h"
 void Servo_init()
 {
    altrasonic_scan.attach(ALTRASONIC_SERVO_PIN);
 }
 void Servo_altrasonic_scan_set_position(unsigned char pos)
 {
    if(pos>=0&&pos<=180)
      {
        if(altrasonic_scan.attached()){altrasonic_scan.write(pos);}
        else{Serial.println("altrasonic_scan servo not attached to pin");return;}
      }
    else{Serial.println("not acceptable angle must be from 0:180");return;}
 }
 unsigned char Servo_altrasonic_scan_get_position()
 {
    if(altrasonic_scan.attached()){return altrasonic_scan.read();}
    else{Serial.println("altrasonic_scan servo not attached to pin");return-1;} 
 }
  
