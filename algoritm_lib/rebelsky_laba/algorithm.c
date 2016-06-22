#include <stdio.h>
#include <stdlib.h>
#include "algorithm.h"

int findLastIndex(int *arr, int size_arr){
	int* indices = (int*)malloc(size_arr*sizeof(int));

	int curIdx = 0;
	int lastIndex = 0;

	for (int i = 0; i < size_arr; i++){
		if (!isInArray(*(arr + i), indices, curIdx)){
			indices[curIdx++] = *(arr + i);
			lastIndex = i;
		}
	}
	return lastIndex;
}

	int isInArray(int number, int *arr, int size_arr){
		for (int i = 0; i <= size_arr; i++){
			if (number == *(arr + i))
				return 1;
		}
		return 0;
	}

	int *array_from_file(char *file_name, int *arr_size){
		FILE *fp;
		int arr[10000];
		int number = 0;
		int i = 0;

		fp = fopen(file_name, "r");

		if (fp == NULL){
			perror("Не удалось прочитать файл.\n");
			exit(EXIT_FAILURE);
		}

		while (fscanf(fp, "%d", &number) > 0)
			arr[i++] = number;


		*arr_size = i;

		fclose(fp);

		return arr;
	}


