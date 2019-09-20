#include<iostream>
using  namespace std;

/*
����		ʱ�临�Ӷ�	�ռ临�Ӷ�   �ȶ���	     �ص�
ð������	O(N^2)		O(1)		 �ȶ�
����		O(N*logN)	O(logN)		 ���ȶ�
ֱ�Ӳ���	O(N^2)		O(1)		�ȶ�		Ԫ����������Խ��
ϣ������   O(N^1.3~N^2)			���ȶ�		��ֱ�������һ����������
ֱ��ѡ������ O(N^2)		O(1)		���ȶ�      �ܺ���⣬����Ч�ʲ��Ǻܸ�
������      O(N*logN)   O(1)		���ȶ�		Ч�ʺܿ�
�鲢����    
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
