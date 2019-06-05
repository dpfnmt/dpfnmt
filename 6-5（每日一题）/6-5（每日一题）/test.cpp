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
��Ŀ����ת��������������ļ������Ӽ�������ÿ�δ�ȫ����ѡ������Ԫ�أ�С������Ӽ������ӣ���
�����Ӽ�����Ϊ2^n����ʹ��dfs��Ȼ��ʱ���Ҵ������ظ�Ԫ�أ���ô��������֦��

  ������������������a,b������� a+b>a*b�������һ����Ϊ1.��������֤���� 
  ��a=1+x,b=1+y����1+x+1+y>(1+x)*(1+y)��--->
   1>x*y����x��y����һ��Ϊ0����a,b��һ��Ϊ1. 
  �ƹ㵽����k��������������a1,a2,...ak������������������������sumС�ڵ��ڻ�pi�� 
  �����ʱ��ѡ��һ����b,��ʹ������sum+b > pi*b����b��ȻΪ1����Ϊ��Ҫ�ǳ�������� 
  ��֮�����ѡ���b>1����sum+b
  <=pi*b����a1,a2,...,ak,b�����������������������֦����Ҫ���ݣ� 

  


  ��ˣ����򰴱����������ÿ�δ�С����ѡ�񣬵�ѡ��a1,a2,...,ak-1ʱ�������������
  ��������ѡ��akʱ������������ak��Ȼ���ڵ���max(a1,a2,...,ak-1)�����������ѡ����������
  ��Ȼ�޷����㣡��ˣ����Խ��м�֦�� 

  ����ж��1������k=1ʱ��sum(1)>pi(1)�����㣬����һ��Ԫ����Ϊ1�����������1+1>1*1��
  ����Ҫ�жϵ�ǰak�Ƿ����1.

  ���⣬�����ظ����֣�Ҫȥ�ظ���*/
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
		// ����1�ĸ���   
		}    if(ones<=0) 
		{ 
			//��1���޽�        
			cout << 0 << endl;        
			return 0;    
		}
	vector<int> prod = { 1 }; //��¼���еĳ˻�    
	vector<int> sum = {0};  //����    
	int pre = 0;   
	for(int i=ones; i<n; ++i) 
	{      
		int m = sum.size();       
		int k = 0;       
		if (number[i] == number[i-1]) 
		{         
			//�����ǰһ��һ����û��Ҫ�ظ���ӵ�ǰ��Ĵ���        
			k = pre;      
		}    
		for( ; k<m; ++k)
		{           
			//����number[i]�������Ӻ��Ƿ������˵ģ��ȸ���1����������У�    
			if(sum[k]+number[i] - prod[k]*number[i] > -ones) 
			{              
				prod.push_back(prod[k] * number[i]);//���浱ǰ���ӳ˻�����            
				sum.push_back(sum[k] + number[i]);
			}       
		}      
		pre = m;    
	}    
	int count = ones > 2 ? ones - 1 : 0;//ֻ��1��ɵ����˴�����   
	for(int k=1; k<sum.size(); ++k) 
	{
		//ͨ�����벻ͬ������1��ʹ����������    
		count += ones + sum[k] - prod[k];
	}    
		cout << count << endl;
	return 0;
}