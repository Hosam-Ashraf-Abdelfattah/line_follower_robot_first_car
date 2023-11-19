#ifndef MOTORDRIVE_H
#define MOTORDRIVE_H


#define left_motor_forward 6
#define left_motor_backward 5
#define right_motor_forward 3
#define right_motor_backward 10
//#define left_control 5
//#define right_control 6


#define normal_forward 200
#define Rerr 0
#define Lerr 5
#define x 20
#define y 40
#define left_speed_min 0
#define left_speed_mid 190 //+++
#define left_speed_max 190 //+++

#define right_speed_min 0
#define right_speed_mid 190
#define right_speed_max 190


void motor_init();
void stop_all();
void forward(unsigned char left_speed,unsigned char right_speed);
void backward(unsigned char left_speed,unsigned char right_speed);
void right(unsigned char left_speed,unsigned char right_speed);
void left(unsigned char left_speed,unsigned char right_speed);
void rotate_right(unsigned char left_speed,unsigned char right_speed);
void rotate_left(unsigned char left_speed,unsigned char right_speed);



#endif
