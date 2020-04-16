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
// 排序结果
void test1(){
	
	int array[] = {200, 10, -1, 2, 9, 34, 3, 5, 7, -5, 100};
	int num = sizeof(array) / sizeof(array[0]);
	int* copy = (int*)malloc(num * sizeof(int));
	int* copy2 = (int*)malloc(num * sizeof(int));
	int* copy3 = (int*)malloc(num * sizeof(int));
	int* copy4 = (int*)malloc(num * sizeof(int));
	int* copy5 = (int*)malloc(num * sizeof(int));


	memcpy(copy, array, sizeof(int)* num);
	memcpy(copy2, array, sizeof(int)* num);
	memcpy(copy3, array, sizeof(int)* num);
	memcpy(copy4, array, sizeof(int)* num);
	memcpy(copy5, array, sizeof(int)* num);

	// 插入排序
	printf("插入排序结果:\n");
	printArray(array, num);
	insertSort(array, num);
	printArray(array, num);
	// 希尔排序
	printf("希尔排序结果:\n");
	printArray(copy, num);
	shellSort(copy, num);
	printArray(copy, num);
	// 选择1排序
	printf("选择1排序结果:\n");
	printArray(copy2, num);
	selectSort(copy2, num);
	printArray(copy2, num);
	// 选择2排序
	printf("选择2排序结果:\n");
	printArray(copy3, num);
	selectSort2(copy3, num);
	printArray(copy3, num);
	// 堆排序
	printf("堆排序结果:\n");
	printArray(copy4, num);
	heapSort(copy4, num);
	printArray(copy4, num);
	// 冒泡排序
	/*printf("冒泡排序结果:\n");
	printArray(copy5, num);
	bubbleSort(copy5, num);
	printArray(copy5, num);*/


}
int test2(){
	int array[] = { 200, 10, -1, 2, 9, 34, 3, 5, 7, -5, 100};
	int num = sizeof(array) / sizeof(array[0]);
	int* copy = (int*)malloc(num * sizeof(int));
	int* copy2 = (int*)malloc(num * sizeof(int));
	int* copy3 = (int*)malloc(num * sizeof(int));
	int* copy4 = (int*)malloc(num * sizeof(int));
	int* copy5 = (int*)malloc(num * sizeof(int));

	memcpy(copy, array, sizeof(int)* num);
	memcpy(copy2, array, sizeof(int)* num);
	memcpy(copy3, array, sizeof(int)* num);
	memcpy(copy4, array, sizeof(int)* num);
	memcpy(copy5, array, sizeof(int)* num);

	int begin = 0;
	int end = num - 1;
	printf("快速排序结果:\n");
	printArray(array, num);
	quickSort(array, begin, end);
	printArray(array, num);

	printf("快排非递归1排序结果:\n");
	printArray(copy, num);
	quickSortNor1(copy, num);
	printArray(copy, num);


	printf("快排非递归2排序结果:\n");
	printArray(copy2, num);
	quickSortNor2(copy2, num);
	printArray(copy2, num);

	printf("归并排序结果:\n");
	printArray(copy3, num);
	mergeSort(copy3, num);
	printArray(copy3, num);

	printf("归并排序非递归结果:\n");
	printArray(copy4, num);
	mergeSortNor(copy4, num);
	printArray(copy4, num);

	printf("计数排序结果:\n");
	printArray(copy5, num);
	countSort(copy5, num);
	printArray(copy5, num);
}

// 效率
int testTime(){
	int n;
	int* array, *copy, *copy2, *copy3, *copy4, *copy5, *copy6, *copy7, *copy8, *copy9, *copy10, *copy11;
	printf("输入未排序元素个数: \n");
	scanf("%d", &n);

	array = (int*)malloc(sizeof(int)* n);
	copy = (int*)malloc(sizeof(int)* n);
	copy2 = (int*)malloc(sizeof(int)* n);
	copy3 = (int*)malloc(sizeof(int)* n);
	copy4 = (int*)malloc(sizeof(int)* n);
	copy5 = (int*)malloc(sizeof(int)* n);
	copy6 = (int*)malloc(sizeof(int)* n);
	copy7 = (int*)malloc(sizeof(int)* n);
	copy8 = (int*)malloc(sizeof(int)* n);
	copy9 = (int*)malloc(sizeof(int)* n);
	copy10 = (int*)malloc(sizeof(int)* n);
	copy11 = (int*)malloc(sizeof(int)* n);

	srand(time(NULL));
	for (int i = 0; i < n; ++i){
		array[i] = rand();
	}

	memcpy(copy, array, sizeof(int)* n);
	memcpy(copy2, array, sizeof(int)* n);
	memcpy(copy3, array, sizeof(int)* n);
	memcpy(copy4, array, sizeof(int)* n);
	memcpy(copy5, array, sizeof(int)* n);
	memcpy(copy6, array, sizeof(int)* n);
	memcpy(copy7, array, sizeof(int)* n);
	memcpy(copy8, array, sizeof(int)* n);
	memcpy(copy9, array, sizeof(int)* n);
	memcpy(copy10, array, sizeof(int)* n);
	memcpy(copy11, array, sizeof(int)* n);



	size_t begin = clock();
	insertSort(array, n);
	size_t end = clock();
	printf("插入排序所用时间为: %d\n", end - begin);


	begin = clock();
	shellSort(copy, n);
	end = clock();
	printf("希尔排序所用时间为: %d\n", end - begin);


	begin = clock();
	selectSort(copy2, n);
	end = clock();
	printf("选择1排序所用时间为: %d\n", end - begin);


	begin = clock();
	selectSort2(copy3, n);
	end = clock();
	printf("选择2排序所用时间为: %d\n", end - begin);


	begin = clock();
	heapSort(copy4, n);
	end = clock();
	printf("堆排序所用时间为: %d\n", end - begin);


	begin = clock();
	bubbleSort(copy5, n);
	end = clock();
	printf("冒泡排序所用时间为: %d\n", end - begin);

	begin = clock();
	quickSort2(copy6, 0, n - 1);
	end = clock();
	printf("快速排序所用时间为: %d\n", end - begin);

	// 栈溢出了, 时间复杂度变大了,数据大的时候 深度变大了, 递归调用更多
	//begin = clock();
	//quickSort(copy6, 0, n - 1);
	//end = clock();
	//printf("快速排序所用时间为: %d\n", end - begin);

	// 优化后变有序再进行快排 就不会崩了 
	begin = clock();
	quickSort(copy6, 0, n - 1);
	end = clock();
	printf("快速排序2(有序时)所用时间为: %d\n", end - begin);


	begin = clock();
	quickSortNor1(copy7, n);
	end = clock();
	printf("快速排序非递归1所用时间为: %d\n", end - begin);

	begin = clock();
	quickSortNor2(copy8, n);
	end = clock();
	printf("快速排序非递归2所用时间为: %d\n", end - begin); 
	
	
	begin = clock();
	mergeSort(copy9, n);
	end = clock();
	printf("归并排序所用时间为: %d\n", end - begin);

	begin = clock();
	mergeSortNor(copy10, n);
	end = clock();
	printf("归并排序非递归所用时间为: %d\n", end - begin);

	begin = clock();
	countSort(copy11, n);
	end = clock();
	printf("计数排序所用时间为: %d\n", end - begin);
}

int main(){

	test1();
	test2();
	testTime();

	system("pause");
	return 0;

}