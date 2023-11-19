#include"GY31.h"

int whiteFrequency = 0;
int greenFrequency = 0;
int blackFrequency = 0;



void GY31_Init(void) {
  // Setting the outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  // Setting the sensorOut as an input
  pinMode(sensorOut, INPUT);
  
  // Setting frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  // Begins serial communication
  //Serial.begin(9600);
}

char GY31_GetColor(void) {
	char color = notInterested;
	// Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  // Reading the output frequency
  whiteFrequency = pulseIn(sensorOut, LOW);

  
  // Printing the RED (R) value
  Serial.print("w = ");
  Serial.print(whiteFrequency);
  delay(10);
  
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  greenFrequency = pulseIn(sensorOut, LOW);

  
  // Printing the GREEN (G) value  
  Serial.print(" G = ");
  Serial.print(greenFrequency);
  delay(10);
 
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  blackFrequency = pulseIn(sensorOut, LOW);
 
  // Printing the BLUE (B) value 
  Serial.print(" B = ");
  Serial.print(blackFrequency);
  delay(10);
  Serial.println(" ");
  // Checks the current detected color and prints
  // a message in the serial monitor
  if((((int)1728 >= whiteFrequency)&&(whiteFrequency >= (int)400)  )&& (((int)400 <=greenFrequency)&&(greenFrequency <=(int)1100))&&(((int)300 <= blackFrequency) && (blackFrequency<=(int)1281))){
      Serial.println(" - black detected!");
	  color = black;
  }
  else if((( (int)422 >= whiteFrequency)&&(whiteFrequency >= (int)250)  )&& (((int)180 <=greenFrequency)&&(greenFrequency <=(int)297))&&(((int)150 <= blackFrequency) && (blackFrequency<=(int)500))){
    Serial.println(" - GREEN detected!");
	color = green;
  }
  else if((((int)200 >= whiteFrequency)&&(whiteFrequency >= (int)0)  )&& (((int)0 <=greenFrequency)&&(greenFrequency <=(int)150))&&(((int)0 <= blackFrequency) && (blackFrequency<=(int)125))){
    Serial.println(" - white detected!");
	color = white;
  }
  else { Serial.print(" not detect ");color = notInterested;}
  
  return color;
}
