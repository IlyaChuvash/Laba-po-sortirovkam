#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "arrays.h"

int* create_rand_arr_int(int N) 
{
	int* arr = (int*)malloc(sizeof(int) * N);

	srand(time(NULL));

	for (int i = 0; i < N; i++) 
	{
		arr[i] = int(rand());
	}
	return arr;
}

double* create_rand_arr_double(int n)
{
	double* arr = (double*)malloc(sizeof(double) * n);

	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{
		arr[i] = double(rand());
	}
	return arr;
}

