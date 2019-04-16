#include"Sort.h"

//≤Â»Î≈≈–Ú
void Print(int* a,int n)
{
	int i = 0;
	for (i = 0; i <= n -1; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
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


//œ£∂˚≈≈–Ú
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
			}
		}
	}
}

