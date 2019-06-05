//#include<iostream>
//using namespace std;
//class DAY
//{
//public:
//	DAY(int year, int month, int day)
//	:_year(year)
//	, _month(month)
//	, _day(day)
//	{}
//	~DAY()
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day; 
//};
//int main()
//{
//	DAY d1(2019, 3, 5);
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int dataToDay(int year,int month,int day)
//{    
//	if(year<=0||month<=0||month>12||day>31||day<=0) 
//		return -1;    
//	int lemp[12]={31,29,31,30,31,30,31,31,30,31,30,31};    
//	int Nolemp[12]={31,28,31,30,31,30,31,31,30,31,30,31};    
//	bool flag;    
//	if((year%4==0 && year%100!=0) || (year%400==0))       
//		flag = true;    
//	else       
//		flag = false;    
//	if(flag)      
//	{        
//		if(day>lemp[month-1]) 
//			return -1;    
//	}   
//	else        
//	{        
//		if(day>Nolemp[month-1])
//			return -1;    
//	}    
//	int tmp=0;    
//	for(int i=0;i<month-1;i++)       
//	{          
//		if(flag)             
//			tmp=tmp+lemp[i];          
//		else            
//			tmp=tmp+Nolemp[i];      
//	}    return tmp+day;} 
//int main()
//{    
//	int year,month,day;    
//	while(cin>>year>>month>>day)   
//	{       
//		cout<<dataToDay(year,month,day)<<endl;   
//	}     
//}
/*
题目可以转化成求符合条件的集合真子集个数。每次从全集中选择若干元素（小球）组成子集（袋子）。
集合子集个数为2^n个，使用dfs必然超时。且此题有重复元素，那么就搜索剪枝。

  对于任意两个正整数a,b如果满足 a+b>a*b，则必有一个数为1.可用数论证明： 
  设a=1+x,b=1+y，则1+x+1+y>(1+x)*(1+y)，--->
   1>x*y，则x，y必有一个为0，即a,b有一个为1. 
  推广到任意k个正整数，假设a1,a2,...ak，如果不满足给定条件，即和sum小于等于积pi， 
  如果此时再选择一个数b,能使其满足sum+b > pi*b，则，b必然为1，且为必要非充分条件。 
  反之，如果选择的b>1，则sum+b
  <=pi*b，即a1,a2,...,ak,b不满足给定条件。（搜索剪枝的重要依据） 

  


  因此，将球按标号升序排序。每次从小到大选择，当选择到a1,a2,...,ak-1时满足给定条件，
  而再增加选择ak时不满足条件（ak必然大于等于max(a1,a2,...,ak-1)），继续向后选择更大的数，
  必然无法满足！因此，可以进行剪枝。 

  如果有多个1，即当k=1时，sum(1)>pi(1)不满足，但下一个元素仍为1，则可以满足1+1>1*1，
  所以要判断当前ak是否等于1.

  此外，对于重复数字，要去重复。*/
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> number(n);
	for (int i = 0; i < n; i++)
	{
		cin >> number[i];
	}
		sort(number.begin(), number.end());    
		int ones = 0;    
		while (ones<n && number[ones] == 1) 
		{
			++ones; 
		// 计算1的个数   
		}    if(ones<=0) 
		{ 
			//无1则无解        
			cout << 0 << endl;        
			return 0;    
		}
	vector<int> prod = { 1 }; //记录可行的乘积    
	vector<int> sum = {0};  //及和    
	int pre = 0;   
	for(int i=ones; i<n; ++i) 
	{      
		int m = sum.size();       
		int k = 0;       
		if (number[i] == number[i-1]) 
		{         
			//如果与前一数一样就没必要重复添加到前面的袋子        
			k = pre;      
		}    
		for( ; k<m; ++k)
		{           
			//加入number[i]到各袋子后，是否是幸运的（比负的1的数量多就行）    
			if(sum[k]+number[i] - prod[k]*number[i] > -ones) 
			{              
				prod.push_back(prod[k] * number[i]);//保存当前袋子乘积及和            
				sum.push_back(sum[k] + number[i]);
			}       
		}      
		pre = m;    
	}    
	int count = ones > 2 ? ones - 1 : 0;//只有1组成的幸运袋子数   
	for(int k=1; k<sum.size(); ++k) 
	{
		//通过加入不同数量的1以使各袋子幸运    
		count += ones + sum[k] - prod[k];
	}    
		cout << count << endl;
	return 0;
}