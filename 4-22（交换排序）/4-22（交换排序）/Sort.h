#ifndef    __SORT_H__
#define    __SORT_H__


#include<stdio.h> 
#include<stdlib.h> 
#include<assert.h> 
#include<malloc.h> 
#include<time.h> 
#include<memory.h>


void InsertSort(int* a, int n);
void ShellSort(int* a, int n);
void SelecSort(int* a, int n);
void HeapSort(int* a, int n);

void BubbleSort(int* a, int n);
void QuickSort(int* a, int left, int right);
void MergeSort(int* a, int n);



void BenchMank(int* a, int n);
void PrintArray(int* a, int n);


#endif
