#include "GY33.h"
 
/* Example code for the Adafruit TCS34725 breakout library */
 
/* Connect SCL    to analog 5
   Connect SDA    to analog 4
   Connect VDD    to 3.3V DC
   Connect GROUND to common ground */
   
/* Initialise with default values (int time = 2.4ms, gain = 1x) */
// Adafruit_TCS34725 tcs = Adafruit_TCS34725();
 
/* Initialise with specific int time and gain values */
Adafruit_TCS34725 tcs = Adafruit_TCS34725(700, 1);
unsigned int color_G[4] = {136,269,245,670};
unsigned int color_W[4]= {193,295,294,800};
unsigned int color_B[4]= {105,197,196,521};

unsigned int color_G_ADD[4] = {174,499,597,946};
unsigned int color_W_ADD[4]= {868,1164,1176,3178};
unsigned int color_B_ADD[4]= {34,15,50,132};


 


uint16_t r, g, b, c;
void GY33_Init(void) {
  Serial.begin(115200);
  pinMode(SWITCH,INPUT);
  pinMode(LED,OUTPUT);
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }
  
  // Now we're ready to get readings!
}
 
void recalebrate_color()
{
	digitalWrite(LED,1);///led off in main prog as start and get switch value
	while(!digitalRead(SWITCH));//wait to get black
	tcs.getRawData(&r, &g, &b, &c);
	color_B[0] =r;
	color_B[1] =g;
	color_B[2] =b;
	color_B[3] =c;
	digitalWrite(LED,0);
	delay(3000);
	digitalWrite(LED,1);
	
	while(!digitalRead(SWITCH));//wait to get white
	tcs.getRawData(&r, &g, &b, &c);
	color_W[0] =r;
	color_W[1] =g;
	color_W[2] =b;
	color_W[3] =c;
	digitalWrite(LED,0);
	delay(3000);
	digitalWrite(LED,1);
	
	while(!digitalRead(SWITCH));//wait to get green
	tcs.getRawData(&r, &g, &b, &c);
	color_G[0] =r;
	color_G[1] =g;
	color_G[2] =b;
	color_G[3] =c;
	digitalWrite(LED,0);
	delay(3000);
	digitalWrite(LED,1);
	delay(1000);
	digitalWrite(LED,0);
	
}
 

char GY33_GetColor(void) {
  
  char color_value = notInterested;
  
  tcs.getRawData(&r, &g, &b, &c);
  //colorTemp = tcs.calculateColorTemperature(r, g, b);
  //lux = tcs.calculateLux(r, g, b);
  
  //Serial.print("Color Temp: "); Serial.print(colorTemp, DEC); Serial.print(" K - ");
 // Serial.print("Lux: "); Serial.print(lux, DEC); Serial.print(" - ");
  Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
  Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
  Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
  Serial.println(" ");

   if     ((r>color_G[0] && r<color_G[0]+color_G_ADD[0]) && (g>color_G[1] && g<color_G[1]+color_G_ADD[1]) && (b>color_G[2] && b<color_G[2]+color_G_ADD[2]) && (c>color_G[3] && c<color_G[3]+color_G_ADD[3])){color_value = green;}
  else if((r>color_B[0]  && r<color_B[0]+color_B_ADD[0]) && (g>color_B[1] && g<color_B[1]+color_B_ADD[1]) && (b>color_B[2] && b<color_B[2]+color_B_ADD[2]) && (c>color_B[3]  && c<color_B[3]+color_B_ADD[3] )){color_value = black;}
  else if((r>color_W[0] && r<color_W[0]+color_W_ADD[0]) && (g>color_W[1] && g<color_W[1]+color_W_ADD[1]) && (b>color_W[2] && b<color_W[2]+color_W_ADD[2]) && (c>color_W[3]  && c<color_W[3]+color_W_ADD[3])){color_value = white;}
  else if((r>171 && r<715) && (g>280 && g<1021) && (b>285 && b<1056) && (c>755  && c<2805)){color_value = gray;}
  else if((r>179 && r<792) && (g>235 && g<365) && (b>236 && b<404) && (c>666  && c<1524)){color_value = red;}
  else{color_value = notInterested;}


  return color_value;
}
