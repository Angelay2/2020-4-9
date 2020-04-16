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
	// ������
	printf("��������:\n");
	printArray(copy4, num);
	heapSort(copy4, num);
	printArray(copy4, num);
	// ð������
	/*printf("ð��������:\n");
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
	printf("����������:\n");
	printArray(array, num);
	quickSort(array, begin, end);
	printArray(array, num);

	printf("���ŷǵݹ�1������:\n");
	printArray(copy, num);
	quickSortNor1(copy, num);
	printArray(copy, num);


	printf("���ŷǵݹ�2������:\n");
	printArray(copy2, num);
	quickSortNor2(copy2, num);
	printArray(copy2, num);

	printf("�鲢������:\n");
	printArray(copy3, num);
	mergeSort(copy3, num);
	printArray(copy3, num);

	printf("�鲢����ǵݹ���:\n");
	printArray(copy4, num);
	mergeSortNor(copy4, num);
	printArray(copy4, num);

	printf("����������:\n");
	printArray(copy5, num);
	countSort(copy5, num);
	printArray(copy5, num);
}

// Ч��
int testTime(){
	int n;
	int* array, *copy, *copy2, *copy3, *copy4, *copy5, *copy6, *copy7, *copy8, *copy9, *copy10, *copy11;
	printf("����δ����Ԫ�ظ���: \n");
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
	printf("������������ʱ��Ϊ: %d\n", end - begin);


	begin = clock();
	shellSort(copy, n);
	end = clock();
	printf("ϣ����������ʱ��Ϊ: %d\n", end - begin);


	begin = clock();
	selectSort(copy2, n);
	end = clock();
	printf("ѡ��1��������ʱ��Ϊ: %d\n", end - begin);


	begin = clock();
	selectSort2(copy3, n);
	end = clock();
	printf("ѡ��2��������ʱ��Ϊ: %d\n", end - begin);


	begin = clock();
	heapSort(copy4, n);
	end = clock();
	printf("����������ʱ��Ϊ: %d\n", end - begin);


	begin = clock();
	bubbleSort(copy5, n);
	end = clock();
	printf("ð����������ʱ��Ϊ: %d\n", end - begin);

	begin = clock();
	quickSort2(copy6, 0, n - 1);
	end = clock();
	printf("������������ʱ��Ϊ: %d\n", end - begin);

	// ջ�����, ʱ�临�Ӷȱ����,���ݴ��ʱ�� ��ȱ����, �ݹ���ø���
	//begin = clock();
	//quickSort(copy6, 0, n - 1);
	//end = clock();
	//printf("������������ʱ��Ϊ: %d\n", end - begin);

	// �Ż���������ٽ��п��� �Ͳ������ 
	begin = clock();
	quickSort(copy6, 0, n - 1);
	end = clock();
	printf("��������2(����ʱ)����ʱ��Ϊ: %d\n", end - begin);


	begin = clock();
	quickSortNor1(copy7, n);
	end = clock();
	printf("��������ǵݹ�1����ʱ��Ϊ: %d\n", end - begin);

	begin = clock();
	quickSortNor2(copy8, n);
	end = clock();
	printf("��������ǵݹ�2����ʱ��Ϊ: %d\n", end - begin); 
	
	
	begin = clock();
	mergeSort(copy9, n);
	end = clock();
	printf("�鲢��������ʱ��Ϊ: %d\n", end - begin);

	begin = clock();
	mergeSortNor(copy10, n);
	end = clock();
	printf("�鲢����ǵݹ�����ʱ��Ϊ: %d\n", end - begin);

	begin = clock();
	countSort(copy11, n);
	end = clock();
	printf("������������ʱ��Ϊ: %d\n", end - begin);
}

int main(){

	test1();
	test2();
	testTime();

	system("pause");
	return 0;

}