#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "sort.h"
#pragma warning(disable:4996)

void printArray(int* a, int n){
	for (int i = 0; i < n; ++i){
		printf("%d ", a[i]);
	}
	printf("\n");
}
// ������
void test1(){
	
	int array[] = {200, 10, -1, 2, 9, 34, 3, 5, 7, -5, 100 };
	int num = sizeof(array) / sizeof(array[0]);
	int* copy = (int*)malloc(num * sizeof(int));
	int* copy2 = (int*)malloc(num * sizeof(int));
	int* copy3 = (int*)malloc(num * sizeof(int));
	memcpy(copy, array, sizeof(int)* num);
	memcpy(copy2, array, sizeof(int)* num);
	memcpy(copy3, array, sizeof(int)* num);
	// ��������
	printf("����������:\n");
	printArray(array, num);
	insertSort(array, num);
	printArray(array, num);
	// ϣ������
	printf("ϣ��������:\n");
	printArray(copy, num);
	shellSort(copy, num);
	printArray(copy, num);
	// ѡ��1����
	printf("ѡ��1������:\n");
	printArray(copy2, num);
	selectSort(copy2, num);
	printArray(copy2, num);
	// ѡ��2����
	printf("ѡ��2������:\n");
	printArray(copy3, num);
	selectSort2(copy3, num);
	printArray(copy3, num);

}
// Ч��
int testTime(){
	int n;
	int* array, *copy,copy2 ;
	scanf("%d", &n);
	array = (int*)malloc(sizeof(int)* n);
	copy = (int*)malloc(sizeof(int)* n);
	copy2 = (int*)malloc(sizeof(int)* n);
	srand(time(NULL));
	for (int i = 0; i < n; ++i){
		array[i] = rand();
	}

	memcpy(copy, array, sizeof(int)* n);
	memcpy(copy2, array, sizeof(int)* n);

	size_t begin = clock();
	insertSort(array, n);
	size_t end = clock();
	printf("%d\n", end - begin);

	begin = clock();
	shellSort(copy, n);
	end = clock();
	printf("%d\n", end - begin);


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

	test1();
	//testTime();
	//test3();
	system("pause");
	return 0;

}