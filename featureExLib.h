/****************************************************
 Objective: Feature extraction of real-time data.	*
 Author: Golam Gause Jaman							*
 ****************************************************/ 

#ifndef	FEATUREEXLIB
#define FEATUREEXLIB

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

void initX(double*, int);
void emaWF(double*, int);
double ema(double*, double*, int, int);
double emaPlus(double*, double*, double*, int, int);
double differ(double*);

//Initialize buffer
void initX(double* x, int L)
{
	for(int i=0; i<L; i++) x[i]=0;
}

//Weights as function of time
void emaWF(double* emaW, int L)
{
	for(int i=0; i<L; i++) emaW[i]=1.0/L; 
}

//Exponential moving average: Latest element at the begining of the array
double ema(double* x, double* emaW, int L, int step)
{
	double temp;
	double e=0;

	for(int i=L-1; i>=step; i--) 
	{
		x[i]=x[i-step];
		e+=x[i]*emaW[i];
	}
	for(int j=step-1; j>=0; j--)
	{
		cin >> temp;
		x[j]=temp;
		e+=x[j]*emaW[j];
		//delay before next sample	
	} 
	return e;
}  

//Exponential moving average: Update values from external source
double emaPlus(double* x, double* emaW, double* update, int L, int step)
{
	double temp;
	double e=0;

	for(int i=L-1; i>=step; i--) 
	{
		x[i]=x[i-step];
		e+=x[i]*emaW[i];
	}
	for(int j=step-1; j>=0; j--)
	{
		temp = update[j];
		x[j]=temp;
		e+=x[j]*emaW[j];
		//delay before next sample	
	} 
	return e;
}  

//Amount change in consecutive samples (length of frame = 2) (latest data has zero index)
double differ(double* x)
{
	double temp;
	temp = x[0]-x[1];
	x[1]=x[0];
	return temp;
 } 
#endif
