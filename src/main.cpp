#include "sap.h"
#include <iostream>

#define ROWS 100
#define COLS 2

int main(void)
{
	double X1[ROWS][COLS];
	double X2[ROWS][COLS];
	double C1[ROWS][COLS];
	double C2[ROWS][COLS];

	
	//Init. matrices
	for (int i = 0; i < COLS; i++)
	{
		int a = 0;
		for (int j = 0; j < ROWS; j++)
		{			
			X1[j][i] = a;
			a += 2;
//			std::cout << X1[j][i] << std::endl;
		}
	}

	//prototype void covariance(double** x, double** y, int width, int height);
	//compute covariance for 100x2 matrix (2 columns, 100 rows)
	covariance(X1[0], C1[0], 100, 2);
	return 0;
}
