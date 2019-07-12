//#include<iostream>
//#include<string>
//
//using namespace std;
//int main()
//{    
//	string str, res;  
//	int cnt, count; 
//	while (cin >> str >> res)  
//	{        
//		count = 0;   
//		int j;     
//		for (int i = 0; i < str.length() - res.length() + 1;)   
//		{         
//			string s;      
//			for (j = i; j < res.length() + i; j++)   
//				s += str[j];   
//			if (s == res)     
//			{              
//				count++;      
//				i = j;   
//			}       
//			else         
//				i++;       
//		}       
//		cout << count << endl;  
//	}   
//	return 0;
//}

//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int fib(int n)
//{
//		if (n == 0)
//		{
//			return 0;
//		}
//		if (n == 1 || n == 2)
//		{
//			return 1;
//		}
//		else
//		{
//			return fib(n - 1) + fib(n - 2);
//		}
//}
//int main()
//{
//	int from, to;
//	while (cin >> from >> to)
//	{
//		int ret = fib(from);
//		int ret1 =  fib(to);
//		cout << ret1 - ret << endl;
//	}
//	return 0;
//}

#include<iostream>
using namespace std;
int main()
{   
	long long arr[80]={1,1}; 
	for(int i=2;i<80;i++)
	{       
		arr[i] = arr[i-1]+arr[i-2]; 
	}  
	int from = 0, to = 0; 
	while(cin>>from>>to)
	{    
		long long res = 0;   
		for(int i = from;i<=to;i++)
		{   
			res = res + arr[i-1];  
		}        
		cout<<res<<endl;   
	}   
	return 0;
}