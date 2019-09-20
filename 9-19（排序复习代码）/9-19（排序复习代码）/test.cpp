#include<iostream>
using  namespace std;

/*
排序		时间复杂度	空间复杂度   稳定性	     特点
冒泡排序	O(N^2)		O(1)		 稳定
快排		O(N*logN)	O(logN)		 不稳定
直接插入	O(N^2)		O(1)		稳定		元素有序，排序越快
希尔排序   O(N^1.3~N^2)			不稳定		是直接排序的一种优算排序
直接选择排序 O(N^2)		O(1)		不稳定      很好理解，但是效率不是很高
堆排序      O(N*logN)   O(1)		不稳定		效率很快
归并排序    
*/
void print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void _MargeSort(int* a, int begin, int end, int* tmp)
{
	int begin1 = 0, begin2 = 0, end1 = 0, end2 = 0;
	if (begin >= end)
		return;
	int mid = begin + ((end - begin) >> 1);
	begin1 = begin;
	end1 = mid;
	begin2 = mid + 1;
	end2 = end;
	int index = begin;
	_MargeSort(a, begin, mid, tmp);
	_MargeSort(a, mid + 1, end, tmp);
	while (begin1 <= end1 && begin2  <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	index = begin;
	while (begin <= end)
		a[index++] = tmp[begin++];
}
void MaregeSort(int *a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MargeSort(a, 0, n - 1, tmp);
	free(tmp);
}

int main()
{
	int a[] = {  5, 9, 8, 4, 7, 6, 2, 1, 3, 0 };
	MaregeSort(a, sizeof(a) / sizeof(int));
	print(a, sizeof(a) / sizeof(int));
	return 0;
}
