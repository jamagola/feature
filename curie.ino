/********************************************
 * This program is intended for reading
 * ADC values and transmit over UART 
 * across multiple platform.
 * Author: Golam Gause Jaman
 * email: jamagola@isu.edu
 ********************************************/

#include <math.h>

char *buff;
int L=4;
int sensor;
int dt=100; //0.1 sec.
int pin=A0;

void numerASCII(char*, int, int);
void numerASCII(char*, int);

void setup() {
  buff = new char[L];
  Serial.begin(9600); //Initializing UART with baud rate
}

void loop() {
  sensor=analogRead(pin); //Reading from ADC channel
  //Convert and transmit over UART
  numerASCII(buff, sensor, L);
  //numerASCII(buff, sensor);
  for(int i=0; i<L; i++) Serial.print(buff[i]);
  //Serial.print(buff);
  delay(dt);
}

// Convert numerical reading to ASCII character
void numerASCII(char *buff, int sensor, int L)
{
  for(int i=L-1; i>=0; i--)
  {
    buff[i]=sensor%10 + '0';
    sensor/=10;
    }
}

void numerASCII(char *buff, int sensor)
{ 
  sprintf(buff,"%d\n",sensor);
}

