#ifndef IR_DRIVE_H
#define IR_DRIVE_H

#define IR_second_left A0
#define IR_first_left A1
#define IR_center A2
#define IR_first_right A3
#define IR_second_right 9

void IR_Init();
unsigned char scan_IR();


#endif