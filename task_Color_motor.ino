#include "task_Color_motor.h"

void Task3_Init()
{
  GY31_Init();
  GY33_Init();
  motor_init();
  
}

/* when robot walk through color[0] then color[1] then*/
void Task3()
{ 
  volatile unsigned char color[3][2];
  color[0][0]=GY31_GetColor();
  color[0][1]=GY33_GetColor();
  
   color[1][0]=GY31_GetColor();   //get green
   color[1][1]=GY33_GetColor();
  
   color[2][0]=GY31_GetColor();
   color[2][1]=GY33_GetColor();
  
 if((color[0][1] != green  && color[1][1] != green  && color[2][1] != green) && (color[0][0] == green  ||color[1][0] == green  ||color[2][0] == green) )
 {
    while(GY31_GetColor()== green ){forward(70,70);delay(10);stop_all();}
    if(GY31_GetColor()==black){rotate_left(100,100);delay(1);forward(70,70);stop_all();}
    else{return;}
 } 
else if((color[0][0] != green  && color[1][0] != green  &&color[2][0] != green) &&(color[0][1] == green  ||color[1][1] == green  ||color[2][1] == green))
 {
    while(GY33_GetColor()== green ){forward(70,70);delay(10);stop_all();}
    if(GY33_GetColor()==black){rotate_right(100,100);delay(1);forward(70,70);stop_all();}
    else{return;}
 } 
else if((color[0][0] == green  || color[1][0] == green  ||color[2][0] == green) &&(color[0][1] == green  ||color[1][1] == green  ||color[2][1] == green))
 {
    rotate_right(200,200);delay(5);stop_all();
 }
else {return;}

}
