#include<iostream>
using namespace std;

//void test()
//{
//	char str[20];                        //C++����ַ�����
//	for (int i = 0; i < sizeof(str); i++)
//	{
//		//cin >> str[i];
//		//���Կո�
//		cin.get(str[i]);
//	}
//}
//
//void test1()
//{
//	char str[] = "Hello";                //C++����ַ����
//	for (int i = 0; i < sizeof(str); i++)
//	{
//		 cout << str[i];
//	}
//}
//int main()
//{
//	//test();
//	test1();
//		return 0;
//}

//int main()
//{
//	char str[] = "Hello";                //C++����ַ����
//	for (int i = 0; i < sizeof(str), i++){
//		cout << str[i];
//		return 0;
//}


using namespace std;

//int main()
//{
//	char* str[] = { "Follow me", "Basic", "Great Wall", "Department", "Computer Design" ,"Acomend"};
//	char* p;
//	int i, j, k;
//	for (i = 0; i < 5; i++) {
//		k = i;
//		for (j = i + 1; j < 6; j++) {
//			if (strcmp(str[k], str[j]) > 0)
//				k = j;
//		}
//		p = str[k];
//		str[k] = str[i];
//		str[i] = p;
//	}
//	for (i = 0; i < 5; i++)
//		cout << str[i] << endl;
//
//	system("pause");
//	return 0;
//}

char* flip(char* ptr) {
	char* p1, *p2, temp;
	p1 = p2 = ptr;
	while (*p2++);          //p2ָ���ַ��������ַ�'\0'�����һ���ַ�λ��
	p2 -= 2;                 //p2ָ���ַ��������ַ�'\0'ǰ���һ���ַ�λ�ã�����������������
	while (p1 < p2) 
	{
		temp = *p2;
		*p2 = *p1;
		*p1 = temp;
		p1++;
		p2--;
	}
	return ptr;
}

int main()
{
	char str[200];
	cin.getline(str, 200);
	cout << flip(str) << endl;

	system("pause");
	return 0;
}
