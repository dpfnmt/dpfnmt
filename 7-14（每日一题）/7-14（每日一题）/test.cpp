//#include<stdio.h>
//#include<stdlib.h>
//
//
//void Fun(char* arr1, char* arr2)
//{
//	int i = 0;
//	for (i = 0; i < 6; i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//}
//
//int main()
//{
//	char arr1[] = { "abcdef" };
//	char arr2[] = { "dcbafe" };
//	Fun(arr1, arr2);
//	printf("arr1 = %s\narr2 = %s\n", arr1, arr2);
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>

int main()
{

	int flas = 1;
	double done = 2.0, sum = 1.0, ret;
	while (done <= 100)
	{
		flas = -flas;
		ret = flas / done;
		sum = sum + ret;
		done = done + 1;
	}
	printf("%f\n", sum);
	return 0;
}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int  i;
//	int  cout = 0;
//	for (i = 0; i < 100; i++)
//	{
//		if (i % 10 == 9)               //求个位
//		{
//			cout += 1;
//		}
//	}
//	for (i = 0; i < 100; i++)
//	{
//		if (i / 10 == 9)                 //求十位
//		{
//			cout += 1;
//		}
//	}
//	printf("1到100中共出现9的次数为:%d\n", cout);
//	return 0;
//}



