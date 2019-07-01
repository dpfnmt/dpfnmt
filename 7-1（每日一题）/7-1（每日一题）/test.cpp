//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int a, b;
//	int N;
//	while (cin >> N)
//	{
//		if (N % 10 == 0)
//		{
//			return 1;
//		}
//		a = N / 10;
//		while (a >10)
//		{
//
//		}
//	}
//	return 0;
//}

#include <iostream>
#include <string>
using namespace std;
int Getnum(int num)
{   
	int res = 0;
	while(num)   
	{      
		res += num % 10;
		num /= 10;
	}  
	return res;
}
int main()
{    
	string m;  
	while(cin >> m)   
	{        
		int n=0; 
		for (int i = 0; i<m.size(); i++)
			n += m[i] - '0';
		while(n > 9)      
		{        
			int tmp = n;
			n = Getnum(tmp);
		}      
		cout << n << endl;
	}    
	return 0;
}