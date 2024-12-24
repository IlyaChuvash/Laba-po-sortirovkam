#include "nlognSorts.h"

#define MIN(i, j) (( i < j ) ? i : j )
#define MAX(i, j) (( i > j ) ? i : j )

void swap1(int* a, int* b) {
	int buff = *b;
	*b = *a;
	*a = buff;
}

//идея в том, что мы меняем элементы массивов добавлением нужного элемента умноженного на максимальное 
//число а после делим на него в результате чего изначальное число обращается в ноль и остается только нужное нам
// (A + B*N) = где N > A = A/N + BN/N = 0 + B = B
// источник geek for geeks



void in_place_merge(int * arr, int start, int mid, int end)
{
	if (arr[mid] <= arr[mid + 1])
	{
		return;
	}

	int maximum = MAX(arr[mid], arr[end]) + 1;

	int i = start, j = mid + 1, k = start;
	while (i <= mid && j <= end && k <= end) {

		int e1 = arr[i] % maximum;
		int e2 = arr[j] % maximum;
		if (e1 <= e2) {
			arr[k] += (e1 * maximum);
			i++;
			k++;
		}
		else {
			arr[k] += (e2 * maximum);
			j++;
			k++;
		}
	}

	while (i <= mid) {
		int el = arr[i] % maximum;
		arr[k] += (el * maximum);
		i++;
		k++;
	}

	while (j <= end) {
		int el = arr[j] % maximum;
		arr[k] += (el * maximum);
		j++;
		k++;
	}

	for (int i = start; i <= end; i++)
		arr[i] /= maximum;
}

void merge_sort(int * arr, int start, int end)
{
	if (start < end) {
		int mid = start + (end - start) / 2;

		merge_sort(arr, start, mid);
		merge_sort(arr, mid + 1, end);

		in_place_merge(arr, start, mid, end);
	}
}

int partition(int* arr, int start, int end) { //Ломуто

	int pivot = arr[end];

	int i = start - 1;

	for (int j = start; j < end; j++) {
		if (arr[j] < pivot) {
			i++;
			swap1(&arr[i], &arr[j]);
		}
	}

	swap1(&arr[i + 1], &arr[end]);
	return i + 1;
}

void quick_sort(int * arr, int start, int end)
{
	if (start < end) {
		
		int pi = partition(arr, start, end);
	
	
		quick_sort(arr, start, pi - 1);
		quick_sort(arr, pi + 1, end);
	}
}