#include"Sort.h"
//1.插入排序
void InsertSort(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}
// 2.希尔排序
void ShellSort(int* a, int n)
{
	int i = 0;
	int gap = n;
	int end = 0;
	int tmp = 0;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (i = 0; i <= n - gap - 1; i++)
		{
			end = i;
			tmp = a[end + gap];
			while (end >= 0)
			{

				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
				a[end + gap] = tmp;
				//PrintArray(a,n);
			}
		}
	}
}

void Swap(int* p1, int* p2)
{
	int tmp = 0;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void SelecSort(int* a, int n)   //3.选择排序
{
	int i = 0;
	int begin = 0;
	int end = 0;
	end = n - 1;
	while (begin < end)
	{
		int min = 0;
		int max = 0;
		min = begin;
		max = begin;
		for (i = begin; i <= end; i++)
		{
			if (a[i] > a[max])
				max = i;
			if (a[i] < a[min])
				min = i;
		}
		Swap(&a[begin], &a[min]);
		if (begin == max)
		{
			max = min;
		}
		Swap(&a[end], &a[max]);
		++begin;
		--end;
	}
}


void AdjustDown(int* a, int n, int root)
{
	int parent = 0;
	int child = 0;
	parent = root;
	child = parent * 2 + 1;  //把这两句话写在了while语句中，初始化的数值不对，导致执行次数不对；
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)   //4.堆排序
{

	int i = 0;
	int end = 0;
	for (i = (n - 2) / 2; i >= 0; --i)  //在这里写成了++i,导致程序崩了
	{
		AdjustDown(a, n, i);
	}

	end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

//交换排序
//冒泡排序
void BubbleSort(int* a, int n)
{
	int i = 0;
	int end = n;
	while (end > 0)
	{
		for (i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
			}
		}
		--end;
	}
}
void BubbleSort2(int* a, int n)  //5.冒泡的快速排法，减少时间
{
	int i = 0;
	int end = n;
	while (end > 0)
	{
		int change = 0;
		for (i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				change = 1;
			}
		}
		if (change = 0)
		{
			break;
		}
		--end;
	}
}

//快排

int PartSort1(int* a, int begin, int end)
{
	int key = begin;

	while (begin < end)
	{
		//end找小；
		while (begin < end && a[end] >= a[key])
			--end;

		//end找大；
		while (begin < end && a[begin] <= a[key])
			++begin;

		Swap(&a[begin], &a[end]);
	}
	Swap(&a[key], &a[end]);
	return end;
}
int PartSort2(int* a, int begin, int end) //填坑法
{
	int mid = a[begin];
	while (begin < end)
	{
		//end找小；
		while (begin < end && a[end] >= mid)
			--end;
		a[begin] = a[end]; //这里直接就给过去了，不是之前的交换
		//end找大；
		while (begin < end && a[begin] <= mid)
			++begin;
		a[end] = a[begin];
	}
	a[begin] = mid;

	return begin;

}


int GetMidIndex(int* a, int begin, int end) //主要是怕是有序的时候，这个快排就非常慢；加这个就快的很；
{
	int mid = 0;
	mid = begin + ((begin - end) >> 1);
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
			return end;
	}
	else   //mid < begin
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
			return end;
	}

}
int PartSort3(int* a, int begin, int end)   ////三数取中法
{
	int key = 0;
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);
	key = begin;
	while (begin < end)
	{
		//end找小；
		while (begin < end && a[end] >= a[key])
			--end;

		//end找大；
		while (begin < end && a[begin] <= a[key])
			++begin;

		Swap(&a[begin], &a[end]);
	}
	Swap(&a[key], &a[end]);
	return end;
}

int PartSort4(int* a, int begin, int end)//左右指针法
{
	//int count = begin;
	int key = begin;
	int prev = begin;
	int cur = begin + 1;
	while (cur <= end)
	{

		if (a[cur] <= a[key] && prev++ != cur)
		{
			Swap(&a[prev], &a[cur]);

		}
		++cur;
	}
	Swap(&a[key], &a[prev]); 
	/*printf("\n");
	for (; count<end; ++count)
	{

		printf(" %d ", a[count]);


	}printf("\n");*/
	return key;
}
void QuickSort(int* a, int left, int right)  //6.快排
{
	int div = 0;
	if (left >= right)
		return;
	//没有优化过版本；
	/*div = PartSort4(a,left,right);
	QuickSort(a,left, div-1);
	QuickSort(a,div+1,right);*/

	//优化过的版本；
	if (right - left > 10)
	{
		div = PartSort3(a, left, right);
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
	else
	{
		InsertSort(a + left, right - left + 1);
	}

}

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	int mid = 0;
	int begin1 = 0;
	int end1 = 0;
	int begin2 = 0;
	int end2 = 0;
	int index = 0;
	if (begin >= end)
		return;
	if (end - begin <= 8)        ////小区间优化；
	{
		InsertSort(a + begin, end - begin + 1);
	}
	mid = begin + ((end - begin) >> 1);
	begin1 = begin;
	end1 = mid;        //把这里写成了begin；直接就错了；
	begin2 = mid + 1;
	end2 = end;
	index = begin;
	//子问题
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);
	while (begin1 <= end1 && begin2 <= end2)
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
	//归并结果考回原数组；
	index = begin;
	while (begin <= end)
		a[index++] = tmp[begin++];

}
void MergeSort(int* a, int n)  //7.归并排序      缺点//1.开空间，2.拷贝数据
{
	int* tmp = (int*)malloc(sizeof(int)* n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);

}

void CountSort(int* a, int n)  //8.非比较排序；
{
	int max = 0;
	int min = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i< n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	int range = max - min + 1; //它的范围
	int* count = (int*)malloc(range*sizeof(int));
	memset(count, 0, sizeof(int)*range);
	for (i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	for (i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j++] = i + min;  //不加min就错位了。把不是0的数，就按照0，排序了。
		}
	}
}
void PrintArray(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void BenchMank(int* a, int n)
{
	int n1 = 10000;
	int i = 0;
	int begin1, end1, begin2, end2, begin3, end3, begin4, end4, begin5, end5, begin6, end6, begin7, end7, begin8, end8;
	int* a1 = (int*)malloc(sizeof(int)*n1);
	int* a2 = (int*)malloc(sizeof(int)*n1);
	int* a3 = (int*)malloc(sizeof(int)*n1);
	int* a4 = (int*)malloc(sizeof(int)*n1);
	int* a5 = (int*)malloc(sizeof(int)*n1);
	int* a6 = (int*)malloc(sizeof(int)*n1);
	int* a7 = (int*)malloc(sizeof(int)*n1);
	int* a8 = (int*)malloc(sizeof(int)*n1);
	srand(time(0));
	for (i = 0; i< n1; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
	}

	begin1 = clock();
	InsertSort(a1, n);  //插入
	end1 = clock();
	PrintArray(a1, sizeof(a) / sizeof(int));

	begin2 = clock();
	ShellSort(a2, n);   //希尔
	end2 = clock();
	PrintArray(a2, sizeof(a) / sizeof(int));

	begin3 = clock();
	SelecSort(a3, n);   //选择
	end3 = clock();
	PrintArray(a3, sizeof(a) / sizeof(int));

	begin4 = clock();
	HeapSort(a4, n);    //堆排序
	end4 = clock();
	PrintArray(a4, sizeof(a) / sizeof(int));

	begin5 = clock();
	//CountSort(a5, n); //非比较排序
	end5 = clock();
	PrintArray(a5, sizeof(a) / sizeof(int));

	begin6 = clock();
	BubbleSort2(a6, n);  //冒泡排序
	end6 = clock();
	PrintArray(a6, sizeof(a) / sizeof(int));

	begin7 = clock();
	QuickSort(a7, 0, n);   //快排排序
	end7 = clock();
	PrintArray(a7, sizeof(a) / sizeof(int));

	begin8 = clock();
	MergeSort(a8, n);     //归并排序
	end8 = clock();
	PrintArray(a8, sizeof(a) / sizeof(int));

}
int main()
{
	int a[] = { 9, 2, 1, 5, 4, 3, 6, 8, 7, 5 };
	//InsertSort(a,sizeof(a)/sizeof(0));
	//ShellSort(a,sizeof(a)/sizeof(0));
	//BenchMank(a, sizeof(a) / sizeof(0));
	//SelecSort(a , sizeof(a)/sizeof(0));
	//HeapSort(a , sizeof(a)/sizeof(0));
	//交换排序
	//BubbleSort(a , sizeof(a)/sizeof(0));
	//QuickSort(a , 0 , sizeof(a)/sizeof(0) - 1); //这里没有写减1；导致程序蹦了；
	//MergeSort(a,sizeof(a)/sizeof(0));
	CountSort(a,sizeof(a)/sizeof(0));
	PrintArray(a,sizeof(a)/sizeof(0));
	return 0;
}