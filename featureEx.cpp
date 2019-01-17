/*************************************************
 Objective: Feature extraction of real-time data.*
 Author: Golam Gause Jaman						 *
 *************************************************/ 

#include <iostream>
#include <math.h>
#include "featureExLib.h"

//FFT tools are taken from following source
//source: https://www.nayuki.io/page/free-small-fft-in-multiple-languages

using namespace std;

int main()
{
	int L = 4;
	int step = 1;
	double *x;
	x = new double[L];
	double *emaW;
	emaW = new double[L];
	double *update;
	update = new double[step];
	double y[2];  
	
	char access = 'y';
	double temp;
	
	initX(x,L);
	emaWF(emaW, L);
	
	cout << endl;
	for(int i=0; i<L; i++)
	{
	 cout << "Enter a numeric value: ";
	 temp = ema(x,emaW,L,step);
	 cout <<"EMA:\t" << temp << endl; 
	 for(int j=0; j<L; j++) cout << x[j] << "\t";
	 cout << endl;
	}
	
	initX(x,L);
	for(int i=0; i<L; i++){
		for(int j=0; j<step; j++)
		{
			cout << "Enter a numeric value: ";
			cin >> update[j];
		}
		temp = emaPlus(x,emaW,update,L,step);
	 	cout <<"EMA:\t" << temp << endl; 
	 	for(int k=0; k<L; k++) cout << x[k] << "\t";
		cout << endl;	
	}
	
	initX(y,2);
	for(int i=0; i<L; i++)
	{
	 cout << "Enter a numeric value: ";
	 cin >> y[0];
	 for(int j=0; j<2; j++) cout << y[j] << "\t";
	 cout << endl;
	 temp = differ(y);
	 cout <<"Difference:\t" << temp << endl; 
	 cout << endl;
	}
	
	
	system("pause");
	return 0;
}
