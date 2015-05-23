#include "sap.h"
#include <vector>
#include <iostream>

using namespace std;

//----------------------------------------------
//
// Calculates covariance from given matrix.
// Result matrix is stored to y.
//
//----------------------------------------------
double covariance(double* x, double* y, int rows, int cols)
{
	//Total matrix size
	int size = rows * cols;
	//Covariance matrix
	vector<double> c(size);

	//Calculate first column mean
	double ma = avg(x, rows, cols, 0);

	//Get second column
//	std::cout << "mean a: " << ma << std::endl;

	//Calculate second row mean
	double mb = avg(x, rows, cols, 1);
//	std::cout << "mean b: " << mb << std::endl;

	//Remove mean from random variables
	//by columns

	//First column
	for(int i = 0; i < rows * cols; i++)
	{
		x[i] -= ma;
		i += cols - 1;		
	}

	//Second column
	for(int i = 1; i < rows * cols; i++)
	{
		x[i] -= mb;
		i += cols - 1;
	}
	
	//Build a vector from matrix column
	vector<double> a(length);

	//TODO: make here vectors...
	// some code...
	//...end TODO

	//In matlab, we would have to 
	//transpose it. In C world we just
	//give the same vector.
	double c = dot(&a[0], &a[0], length);
	
	//Finally divide the dot product with mean value
	return c / ma;
}

//----------------------------------------------
//
// Calculates mean for a column in a matrix.
// Parameter i indicates which column index
// is under observation.
//
//----------------------------------------------
double avg(double* x, int rows, int cols, int index)
{
	double a = x[index];
	for (int i = index + cols; i < rows * cols; i++)
	{			
		a += x[i];
		i += cols - 1;
	}
//	std::cout << "sum: " << a << std::endl;
	return a/(double)rows;
}

//----------------------------------------------
//
// Calculates a dot product of vectors x and y.
//
//----------------------------------------------
double dot(double* x, double* y, int length)
{
	//Result of dot product
	double d = 0.0f;	
	for (int i = 0; i< length; i++)
	{
		d += x[i]*y[i];
	}
	return d;
}
