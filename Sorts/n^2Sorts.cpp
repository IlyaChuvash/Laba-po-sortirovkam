#include "n^2Sorts.h"

void swap(double * a, double * b) {
	int buff = *b;
	*b = *a;
	*a = buff;
}


void buble_sort(double* arr, int y, int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		int flag = 0;

		for (int j = 0; j < N - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				flag++;
			}
		}
		if (flag == 0)
			break;
	}
}

void insert_sort(double * arr, int y, int N)
{
	for (int i = 1; i < N; i++) {
		int j = i;
		while (j - 1 >= 0 && arr[j - 1] > arr[j]) {
			swap(&arr[j - 1], &arr[j]);
			j--;
		}
	}

}

void fast_insert_sort(double * arr,int y, int N) {

	for (int i = 1; i < N; i++) {
		double key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}
}

void select_sort(double * arr, int y, int N)
{
	for (int i = 0; i < N; i++)
	{
		int minimum = i;

		for (int j = i + 1; j < N; j++)
		{
			if (arr[j] < arr[minimum])
			{
				minimum = j;
			}
		}
		swap(&arr[i], &arr[minimum]);
	}
}