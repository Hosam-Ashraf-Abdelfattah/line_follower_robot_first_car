#include "IR_Driver.h"

void IR_Init(){

  pinMode(IR_second_right, INPUT);
  pinMode(IR_first_right, INPUT);
  pinMode(IR_center, INPUT);

  pinMode(IR_first_left, INPUT);
  pinMode(IR_second_left, INPUT);  
}
volatile bool num[5];
unsigned char scan_IR() {

  //stop_all();
  num[0] = digitalRead(IR_second_right);
  num[1] = digitalRead(IR_first_right);
  num[2] = digitalRead(IR_center);
  num[3] = digitalRead(IR_first_left);
  num[4] = digitalRead(IR_second_left);

  unsigned char number = 0;

  if (num[0] == 1)
    number = number | (num[0] << 0);
  if (num[1] == 1)
    number = number | (num[1] << 1);
  if (num[2] == 1)
    number = number | (num[2] << 2);
  if (num[3] == 1)
    number = number | (num[3] << 3);
  if (num[4] == 1)
    number = number | (num[4] << 4);
  return number;
}