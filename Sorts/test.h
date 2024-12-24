#pragma once

typedef void (*SortPointerInt)(int*, int, int);

typedef void (*SortPointerDouble)(double*, int, int);


double test_int(SortPointerInt sort, int n);

double test_double(SortPointerDouble sort, int n);