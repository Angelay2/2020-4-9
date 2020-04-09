#include <stdio.h>
#include "sort.h"

void printArray(int* a, int n){
	for (int i = 0; i < n; ++i){
		printf("%d ", a[i]);
	}
	printf("\n");
}

void test(){
	int* array = (int*)malloc(sizeof(int));
}