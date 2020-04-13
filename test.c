#include <stdio.h>
#include "sort.h"

void printArray(int* a, int n){
	for (int i = 0; i < n; ++i){
		printf("%d ", a[i]);
	}
	printf("\n");
}

void test1(){
	
	int array[] = { 10, -1, 2, 9, 3, 5, 7, 24, -5, 100 };
	int num = sizeof(array) / sizeof(array[0]);
	printArray(array, num);
	insertSort(array, num);
	printArray(array, num);
}
int test2(){
	
	int* array = (int*)malloc(sizeof(int));
}

int test3(){
	int array[] = { 10, -1, 2, 9, 3, 5, 7, 24, -5, 100 };
	int num = sizeof(array) / sizeof(array[0]);
	int begin = array[0];
	int end = array[num - 1];
	printArray(array, num);
	quickSort(array, begin, end);
	printArray(array, num);
}
int main(){

	// test1();
	test3();
	system("pause");
	return 0;

}