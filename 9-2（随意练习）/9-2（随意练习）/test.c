//#include<stdio.h>
//#define t_max ((x > y) ? (x) : (y))
//
//int get_max(int x, int y)
//{
//	return t_max;
//}
//int main()
//{
//	int num1 = -10;
//	int num2 = 20;
//	int max = get_max(num1, num2);
//	printf("max = %d\n", max);
//	return 0;
//}

#include<stdio.h>

////
//
//int Strlen(char* str)
//{
//	if (*str == '\0')
//		return 0;
//	else
//		return 1 + Strlen(str+1);
//}
//int main()
//{
//	char *str = "asdfg";
//	int lenth = Strlen(str);
//	printf("%d\n", lenth);
//	return 0;
//}


//int main()
//{
//	int arr[3][4];
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("arr[%d][%d] = %p\n", i, j, &arr[i][j]);
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int num1 = 1;
//	int num2 = 2;
//	int ret = num1 & num2;
//	int ret2 = num1 | num2;
//	int ret3 = num1 ^ num2;
//	printf("ret = %d", ret3);
//	return 0;
//}


//int main()
//{
//	int i = 1;
//	char j = *(char*)(&i);
//	if (j == 1)
//		printf("Ğ¡¶Ë\n");
//	else
//		printf("´ó¶Ë\n");
//
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c = (a>b, a = b + 10, a, b = a + 1);
//	printf("ret = %d\n", c);
//	return 0;
//}

int main()
{
	int i = 0, a = 0, b = 2, c = 3, d = 4;
	//i = a++ && ++b && d++;
	i = a++||++b||d++;
	printf("i = %d\n a = %d\n b = %d\n c = %d\nd = %d\n", i ,a, b, c, d);
	return 0;
}