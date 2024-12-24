#include "arrays.h"
#include "test.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double test_int(SortPointerInt sort, int n)
{
	int* arr = create_rand_arr_int(n);
	
	double stt = clock();

	sort(arr, 0, n);

	double endt = clock();

	double all_time = (endt - stt) / double(CLOCKS_PER_SEC);

	free(arr);
	return all_time;
}

double test_double(SortPointerDouble sort, int n)
{
	double* arr = create_rand_arr_double(n);

	double stt = clock();

	sort(arr, 0, n);

	double endt = clock();

	double all_time = (endt - stt) / double(CLOCKS_PER_SEC);

	free(arr);
	return all_time;
}