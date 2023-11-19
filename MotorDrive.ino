#include"MotorDrive.h"



void motor_init()
{
	pinMode(left_motor_forward ,OUTPUT);
	pinMode(right_motor_forward ,OUTPUT);
	pinMode(left_motor_backward ,OUTPUT);
	pinMode(right_motor_backward ,OUTPUT);
	//pinMode(left_motor_speed ,OUTPUT);
	//pinMode(right_motor_speed ,OUTPUT);
}

void stop_all() {
  digitalWrite(left_motor_forward, 0);
  digitalWrite(left_motor_backward, 0);
  digitalWrite(right_motor_forward, 0);
  digitalWrite(right_motor_backward, 0);
}
//int v = 90;
void forward(int r, int l) {
  //analogWrite(right_control, (r+Rerr));
 // analogWrite(left_control, (l+Lerr));

  analogWrite(left_motor_backward, 0);

  analogWrite(right_motor_backward, 0);
  analogWrite(left_motor_forward, (l+Lerr));
  analogWrite(right_motor_forward, (r+Rerr));
}
void backward(int r, int l) {
 // analogWrite(right_control, r);
 // analogWrite(left_control, l);
  analogWrite(left_motor_forward, 0);

  analogWrite(right_motor_forward, 0);
  analogWrite(left_motor_backward, l);
  analogWrite(right_motor_backward, r);
}
void right(int r, int l) {
  //analogWrite(right_control, r);
  //analogWrite(left_control, l);
  analogWrite(left_motor_backward, 0);
  analogWrite(right_motor_forward, r);
  analogWrite(right_motor_backward, 0);
  analogWrite(left_motor_forward, l);

} /*
*/
void left(int r, int l) {
 // analogWrite(right_control, r);
 // analogWrite(left_control, l);
  analogWrite(left_motor_backward, 0);
  analogWrite(left_motor_forward, l);
  analogWrite(right_motor_backward, 0);
  analogWrite(right_motor_forward, r);
}
void rotate_right(int r, int l) {
  //analogWrite(right_control, r);
 // analogWrite(left_control, l);
  analogWrite(left_motor_backward, 0);
  analogWrite(right_motor_forward, 0);

  analogWrite(left_motor_forward, (l+x));
  analogWrite(right_motor_backward, (r+y));
}
void rotate_left(int r, int l) {
  //analogWrite(right_control, r);
  //analogWrite(left_control, l);
  analogWrite(left_motor_forward, 0);
  analogWrite(right_motor_backward, 0);
  analogWrite(left_motor_backward, (l+y));
  analogWrite(right_motor_forward,(r+x));
}