//#include<iostream>
//#include<string>
//#include<set>
//using namespace std;
//int main()
//{   
//	string s; 
//	int length;   
//	string NUM = "22233344455566677778889999";  
//	while (cin >> length) 
//	{        
//		set<string> data;    
//		int cnt;       
//		for (int i = 0; i < length; i++)   
//		{        
//			cnt = 0;     
//			string res;          
//			cin >> s;           
//			for (int j = 0; j < s.length(); j++)   
//			{              
//				if (s[j] >= 'A'&&s[j] <= 'Z')       
//				{                
//					res += NUM[s[j] - 'A'];   
//					cnt++;                 
//					if (cnt == 3)         
//						res += "-";         
//				}              
//				else if (s[j] >= '0'&&s[j] <= '9')     
//				{                   
//					res += s[j];       
//					cnt++;                
//					if (cnt == 3)           
//						res += "-";        
//				}        
//			}          
//			data.insert(res);  
//		}        
//		for (set<string>::iterator it = data.begin(); it != data.end(); it++)  
//			cout << *it << endl;      
//			cout << endl;  
//	}   
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <set>
//using namespace std;
//int main()
//{   
//	int n;
//	string mapper[2] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ",                         "22233344455566677778889999" };
//	while (cin >> n && n)   
//	{        
//		string str, temp;    
//		set<string, less<string> > list;    
//		for (int i = 0; i < n; ++i)  
//		{           
//			cin >> str; temp = "";      
//			for (char ch : str)        
//			{               
//				if (ch != '-' && isalpha(ch))  
//					temp += mapper[1][toupper(ch) - 'A'];   
//				else if (ch != '-' && isalnum(ch))   
//					temp += ch;      
//			}         
//			temp.insert(temp.begin() + 3, '-');     
//			list.insert(temp);       
//		}        
//		for (string str : list) cout << str << endl;    
//		cout << endl;  
//	}    
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//void help(int n, int m, vector<int>& v, int beg)
//{    
//	//if (beg>n)
//	//return;    
//	if (m == 0) 
//	{     
//		for (int i = 0; i<v.size(); i++)
//		{   
//			i == 0 ? cout << v[i] : cout << " " << v[i];      
//		}        
//		cout << endl; 
//	}    for (int i = beg; i <= n&&i <= m; i++) {        v.push_back(i);        help(n, m - i, v, i + 1);        v.pop_back();    }}int main() {    int n, m;    while (cin >> n >> m) {        vector<int>v;        help(n, m, v, 1);    }
//}

//#include<iostream>
//#include<string>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	char arr[1000];
//	//vector<string> v;
//	while (cin >> arr)
//	{
//		for (int i = 0; i < 100; i++)
//		{
//			if (arr[i] == '_')
//			{
//				arr[i] = arr[i + 1];
//				arr[i] = arr[i] - 32;
//			}
//		}
//		cout << arr << endl;
//	
//
//	return 0;
//}

//#include<string>
//#include<iostream>
//using namespace std;
//int main()
//{  
//	string s; 
//	while(cin>>s)
//	{      
//		int len = s.size();   
//		string::iterator it=s.begin();  
//		while(it!=s.end())
//		{           
//			if(*it=='_')
//			{       
//				it = s.erase(it);   //去除'_'     
//				*it -= 32; //将下一位字母由小写转换为大写   
//			}
//			else
//			{  
//				it++;   
//			}      
//		}      
//		cout<<s<<endl;
//	}  
//	return 0;
//}

#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{    
	string str;   
	while(getline(cin,str))   
	{      
		vector<string> sv; 
		sv.clear();   
		string temp="";  
		for(int i=0;i<str.size();++i) 
		{          
			if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z')
				temp+=str[i]; 
			else          
			{         
				if(temp.size()>0)  
				{                
					sv.push_back(temp); 
					temp="";   
				}   
			} 
		}      
		if(temp.size()>0)  
			sv.push_back(temp); 
		for(int i=sv.size()-1;i>0;--i) 
			cout<<sv[i]<<' ';
		cout<<sv[0]<<endl;    
	}    
	return 0;
}