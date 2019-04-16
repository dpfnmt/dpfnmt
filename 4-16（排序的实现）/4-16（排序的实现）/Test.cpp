#include"Sort.h"


int main()
{
	int a[] = { 1, 2, 5, 6, 9, 8, 7, 4, 3 };
	InsertSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int)); 
	ShellSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
	return 0;
}