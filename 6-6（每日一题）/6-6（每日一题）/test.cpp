//#include<iostream>
//using namespace std;
// int main()
// {    
//	 int n;  
//	 while(cin >> n)    
//	 {      
//		 int count = 0;   
//		 while(n > 0)       
//		 {           
//			 if(n & 1)
//		     ++count;     
//			 n >>= 1;       
//		 }        
//		 cout << count << endl;    
//	 }    
//	 return 0;
//}

#include<bits.h>
#include<iostream>;
using namespace std;
int main()
{
	int n, sum, cnt;
	while (cin >> n)
	{
		cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			sum = 0;
			for (int j = 1; j<i; j++)

			if (i%j == 0) sum += j;
			if (sum == i) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}