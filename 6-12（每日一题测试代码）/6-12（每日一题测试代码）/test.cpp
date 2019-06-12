
#include<iostream>
#include<string>

using namespace std;

//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		for (int i = str.size() - 1; i >= 0; i--)
//		{
//			cout << str[i] << endl;
//		}
//	}
//	return 0;
//}

//int getStrLenth(string str1, string str2)
//{
//	int count = 0;
//	for (int i = 0; i < str1.size(); i++)
//	{
//		if (str1[i] < 'A' || str1[i] >'Z')
//		{
//			str1[i] -= 32;
//		}
//		for (int j = 0; i < str2.size(); j++)
//		{
//			if (str2[j] < 'A' || str2[j] >'Z')
//			{
//				str2[j] -= 32;
//			}
//			else
//			{
//				if (str1[i] != str2[j])
//				{
//					str2[j] = str2[j + 1];
//				}
//				else
//				{
//					str1[i] = str1[i + 1];
//					str2[j] = str2[j + 1];
//					count++;
//				}
//			}
//		}
//	return  count;
//	}
//}
//int main()
//{
//	string str1,str2;
//	while (cin >> str1>>str2)
//	{
//		getStrLenth(str1, str2);
//	}
//	return 0;
//}


#include<iostream>
#include <string>
using namespace std; 
int main(){  
	string str1, str2;  
	int cnt = 0, pos = 0;    
	string tmp;  
	while(cin >> str1 >> str2) 
	{    
		for(int i = str1.length(); i > 0; i--)   
		{         
			for(int j = 0; j < str1.length(); j++)        
			{             
				tmp = str1.substr(j,i);      
				pos = str2.find(tmp);          
				if(pos != string::npos && tmp.length() > cnt)         
					cnt = tmp.length();        
			}   
		
		}    
		cout << cnt <<endl; 
	}     
	return 0;
}
