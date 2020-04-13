#pragma once

void Swap(int a, int b);
void insertSort(int* array, int n);
void shellSort(int* array, int n);
void selectSort(int* array, int n);
void selectSort2(int* array, int n);

void shiftDown(int* array, int n, int parent);
void heapSort(int* array, int n);
void bubbleSort(int* array, int n);
int partion(int* array, int begin, int end);
int partion2(int* array, int begin, int end);
int partion3(int* array, int begin, int end);
void quickSort(int* array, int begin, int end);