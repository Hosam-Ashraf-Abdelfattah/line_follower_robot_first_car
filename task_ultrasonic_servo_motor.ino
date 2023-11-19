#include "task_ultrasonic_servo_motor.h"
//#define arc 15
void Task2_Init() {

  IR_Init();
  Servo_init();
  AltraSonic_init();
  Serial.begin(9600);
  Servo_altrasonic_scan_set_position(180); 


}

void Task2() {
//task:start with detect obstacle with altrsonic
//when it detected task start with motor start turn left but must scaled with altrasonic with servo 
//when motor start rotate around obstacle clock wicely servo start angle to be 
   
 
  Serial.print("distance:");      
  Serial.println(get_distance());
  delay(1000);
  Serial.println(Servo_altrasonic_scan_get_position());
  int i;
if  (get_distance()<6)
{
  
  for (i=0;get_distance()<10&&Servo_altrasonic_scan_get_position()>0;i++)
    {
      Servo_altrasonic_scan_set_position(180-i); 
      left(left_speed_mid,right_speed_mid);
    }
  for (;get_distance()>10 && scan_IR()==0  ;i++)
    {
      Servo_altrasonic_scan_set_position(180-i);
      right(left_speed_mid,right_speed_mid);
    }
}
 Servo_altrasonic_scan_set_position(180);
  
}
