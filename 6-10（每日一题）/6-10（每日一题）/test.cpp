#include<iostream>
using namespace std;

//int getFib(int i)
//{
//	if (i == 1 || i == 2)
//		return 1;
//	else
//		return getFib(i - 1) + getFib(i - 2);
//}
//int main()
//{
//	int N;
//	int ret;
//	while (cin >> N)
//	{
//		cout << getFib(N) << endl;
//
//	}
//	return 0;
//}

//int main()
//{
//	    int  N, val;
//		int count = 0;
//		while (cin >> N)
//		{
//			while (N > 1)
//			{
//				val = N / 3 + N % 3;
//				count += N / 3;
//				N = val;
//				if (N == 2)
//				{
//					count++;
//					break;
//				}
//			}
//			cout << count << endl;
//			count = 0;
//		}
//		return 0;
//}

//int main()
//{
//	int n; 
//	while (cin >> n)
//	{
//		cout << n / 2 << endl;
//	}
//	return 0;
//}

#include<string>
//int main()
//{
//	string s1;
//	string s2;
//	while (cin >> s1 >> s2)
//	{
//		for (int i = 0; i < s1.length(); i++)
//		{
//			for (int j = 0; j < s2.length(); j++)
//			{
//				if (s1[i] == NULL || s2[j] == NULL)
//				{
//					return NULL;
//				}
//				else
//				{
//					if (s1[i] == s2[j])
//					{
//						s1[i]++;
//						s2[j]++;
//					}
//					else if (s1[i] != s2[j])
//					{
//						s1[i]++;
//					}
//					else
//					{
//						break;
//					}
//				}
//				cout << s1[i] << endl;
//			}
//		}
//	}
//	return 0;
//}