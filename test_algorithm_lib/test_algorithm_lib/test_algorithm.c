#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "algorithm.h"
#include "test_algorithm.h"



int main(int argc, char *argv[]){
	setlocale(LC_CTYPE, "rus");
	int *arr = NULL;
	int arr_size = 0; 
	int lastIndex;

	if (argc < 2){
		print_help();
		return 0;
	}else{
		char *arg = argv[1];
		if (!strcmp(arg, "-help") || !strcmp(arg,"-h")){
			print_help();
			return 0;
		}
		else if (!strcmp(arg, "-file")){
			arr = array_from_file(argv[2], &arr_size);
		}
		else if (!strcmp(arg, "-manual")){
			arr = array_from_cmd(argv, argc, &arr_size);
		}
		else{
			printf("\nunexpected argument\n");
			exit(EXIT_FAILURE);
		}

		
		lastIndex = findLastIndex(arr, arr_size);
		printf("\nlast index is %d", lastIndex);
		return 0;
	}
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

	while (fscanf(fp,"%d", &number) > 0)
		arr[i++] = number;
	
	
	*arr_size = i;

	fclose(fp);

	return arr;
}



int *array_from_cmd(char *argv[], int arg_size, int *arr_size){
	printf("Считали массив данных из командной строки\n");
	int *arr = (int*)malloc((arg_size - 2)*sizeof(int));
	
	for (int i = 2; i < arg_size; *(arr + i++ - 2) = atoi(argv[i]));

	*arr_size = arg_size - 2;
	return arr;
}

void print_help(void){
	printf("\n-file filePath    - чтение массива данных из файла\n");
	printf("-manual args      - чтение массива данных из консоли");
	return 0;
}

