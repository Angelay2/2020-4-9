#pragma once

void Swap(int a, int b);
void insertSort(int* array, int n);
void shellSort(int* array, int n);
void selectSort(int* array, int n);
void selectSort2(int* array, int n);

void shiftDown(int* array, int n, int parent);
void heapSort(int* array, int n);
void bubbleSort(int* array, int n);
int getMid(int* array, int left, int right);
int partion(int* array, int begin, int end);
int partion2(int* array, int begin, int end);
int partion3(int* array, int begin, int end);
void quickSort(int* array, int begin, int end);
void quickSortNor1(int* array, int n); 
void quickSortNor2(int* array, int n);
void mergeInternal(int* array, int left, int mid, int right, int* tmp);
void merge(int* array, int left, int right, int* tmp);
void mergeSort(int* array, int n);
void mergeSortNor(int* array, int n);
void countSort(int* array, int n);
