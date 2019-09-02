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

//

int Strlen(char* str)
{
	if (*str == '\0')
		return 0;
	else
		return 1 + Strlen(str+1);
}
int main()
{
	char *str = "asdfg";
	int lenth = Strlen(str);
	printf("%d\n", lenth);
	return 0;
}

