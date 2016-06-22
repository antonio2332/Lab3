#include <stdio.h>

__declspec(dllexport) int findLastIndex(int *arr, int size_arr);
__declspec(dllexport) int *array_from_file(char *file_name, int *arr_size);
int isInArray(int number, int *arr, int size_arr);
