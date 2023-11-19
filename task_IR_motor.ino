#include "task_IR_motor.h"


void Task1_Init() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(left_motor_forward, OUTPUT);
  pinMode(right_motor_forward, OUTPUT);
  pinMode(left_motor_backward, OUTPUT);
  pinMode(right_motor_backward, OUTPUT);
 // pinMode(left_control, OUTPUT);
  //pinMode(right_control, OUTPUT);


  pinMode(IR_second_right, INPUT);
  pinMode(IR_first_right, INPUT);
  pinMode(IR_center, INPUT);

  pinMode(IR_first_left, INPUT);
  pinMode(IR_second_left, INPUT);
}
volatile unsigned char read;
void Task1() {
  read = scan_IR();
  switch (read) {
    case 0:  //front mid 00000
      forward(normal_forward, normal_forward);
      Serial.println("front mid 00000");
      break;
    case 0x1F:  ////front mid 11111
      forward(normal_forward, normal_forward);
      Serial.println("front mid 11111");
      break;
    case 0x11:  ////front mid 10001
      forward(normal_forward, normal_forward);
      Serial.println("front mid 10001");
      break;
    case 0x1B:  ////front mid 11011
      forward(normal_forward, normal_forward);
      Serial.println("front mid 11011  ");
      break;
    case 0x0E:  ////front mid 01110
      forward(normal_forward, normal_forward);
      Serial.println("front mid 01110 ");
      break;
    case 0x0A:  ////front mid 01010
      forward(normal_forward, normal_forward);
      Serial.println("front mid 01010 ");
      break;


    case 0x01:  ////left max 00001
                //left(right_speed_max,0);
      rotate_left(right_speed_max, left_speed_mid);
      Serial.println("left max 00001");
      break;
    case 0x03:  ////left max 00011
                //left(right_speed_max,0);
      rotate_left(right_speed_max, left_speed_mid);
      Serial.println("left max 00011");
      break;
    case 0x07:  ////left mid 00111
                //left(right_speed_max,left_speed_min);
      rotate_left(right_speed_max, left_speed_mid);
      Serial.println("left mid 00111");
      break;
    case 0x0F:  ////left mid 01111
                //left(right_speed_max,left_speed_min);
      rotate_left(right_speed_max, left_speed_mid);
      Serial.println("left mid 01111 ");
      break;
    case 0x06:  ////left mini 00110
      rotate_left(right_speed_mid, left_speed_min);
      Serial.println("left mini 00110 ");
      break;
    case 0x02:  ////left mid 00010
      rotate_left(right_speed_max, left_speed_min);
      Serial.println("left mid 00010  ");
      break;
    case 0x13:  ////left mid 10011
                //left(right_speed_max,left_speed_min);
      rotate_left(right_speed_max, left_speed_mid);
      Serial.println("left mid 10011  ");
      break;
      
      break;
    case 0x17:  ////left mid 10111
                //left(right_speed_max,left_speed_min);
      rotate_left(right_speed_max, left_speed_mid);
      Serial.println("left mid 10111    ");
      break;
       /*  case 0x05:  ////right mid 00101  *****
       rotate_left(right_speed_max, left_speed_mid);
      Serial.println("left mid 10111    ");
      break;
       case 0x09:  ////left mid 01001
                //left(right_speed_max,left_speed_min);
      rotate_left(right_speed_max, left_speed_mid);
      Serial.println("left mid 10011  ");
 case 0x0D:  ////right mid 01101  *****
       rotate_left(right_speed_max, left_speed_mid);
      Serial.println("left mid 10111    ");
    break;
    */


    case 0x10:  ////right max 10000
      //right(0,left_speed_max);
      rotate_right(right_speed_mid, left_speed_max);
      Serial.println("right max 10000 ");
      break;
    case 0x18:  ////right max 11000
                //right(0,left_speed_max);
      rotate_right(right_speed_mid, left_speed_max);
      Serial.println("right max 11000 ");
      break;
    case 0x1C:  ////right mid 11100
                //right(right_speed_min,left_speed_max);
      rotate_right(right_speed_mid, left_speed_max);
      Serial.println("right mid 11100 ");
      break;
    case 0x1E:  ////right mid 11110
                //right(right_speed_min,left_speed_max);
      rotate_right(right_speed_mid, left_speed_max);
      Serial.println("right mid 11110 ");
      break;
    case 0x08:  ////right mid 01000
      rotate_right(right_speed_min, left_speed_max);
      Serial.println("right mid 01000 ");
      break;
        /* case 0x14:  ////right mid 10100  *****
      right(right_speed_min, left_speed_max);
      Serial.println("right mid 01000 ");
      break;
 case 0x16:  ////right mid 10110  *****
      right(right_speed_min, left_speed_max);
      Serial.println("right mid 01000 ");
      break;
       case 0x12:  ////right mid 10010  *****
      right(right_speed_min, left_speed_max);
      Serial.println("right mid 01000 ");
      break; 
      */     
      
    case 0x0C:  ////right mini 01100
      rotate_right(right_speed_min, left_speed_max);
      Serial.println("right mini 01100 ");
      break;
    case 0x19:  ////right mini 11001
                //right(right_speed_min,left_speed_max);
      rotate_right(right_speed_mid, left_speed_max);
      Serial.println("right mini 11001 ");
      break;
    case 0x1D:  ////right mini 11101
                //right(right_speed_min,left_speed_max);
      rotate_right(right_speed_mid, left_speed_max);
      Serial.println("right mini 11101 ");
      break;

    default:
      forward(right_speed_mid, left_speed_mid);
      Serial.println("default");
      break;
  }
  stop_all();
  Serial.print(read);
  Serial.print(" = ");
  Serial.print(num[4]);
  Serial.print(num[3]);
  Serial.print(num[2]);
  Serial.print(num[1]);
  Serial.println(num[0]);


  ///white is  1
  /*
 11011 forward mid
 10001 forward
  11111 forward
  00000 forward
01110 forward

00001 left max
00011 left max
00111 left mid
01111 left mid
00110 left mini
00010 left mid


10000 right max
11000 right max
11100 right mid
11110 right mid
01100 right mini
01000 right mid



  
 */
}
