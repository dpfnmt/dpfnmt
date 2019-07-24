//#include <iostream>
//#include <fstream>
//#include <algorithm>
//#include <string>
//#include <set>
//
//using namespace std;
//int main()
//{    
//	int n;  
//	while (cin >> n)  
//	{      
//		set<string> pool;  
//		string id, con;    
//		int maxSize = 0;     
//		for (int i = 0; i < n; ++i)  
//		{          
//			cin >> id >> con;  
//			if (con == "connect") 
//				pool.insert(id);  
//			else if (con == "disconnect") 
//				pool.erase(id);      
//			int size = pool.size();   
//			maxSize = max(maxSize, size);  
//		}       
//		cout << maxSize << endl; 
//	}   
//	return 0;
//}


#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int main()
{    
	int n; 
	while (cin >> n)  
	{    
		vector<string> list(n);   
		vector<bool> flag(n, true);  
		for (int i = 0; i < n; ++i) 
			cin >> list[i];  
		sort(list.begin(), list.end());  
		for (int i = 0; i < list.size() - 1; ++i)  
		{           
			// 1��������ͬ         
			// 2��ǰ���Ǻ󴮵��Ӵ������Һ󴮺�һλ�� '/' 
			if (list[i] == list[i + 1]) 
				flag[i] = false;          
			else if (list[i].size() < list[i + 1].size() 
				&& list[i] == list[i + 1].substr(0, list[i].size()) 
				&& list[i + 1][list[i].size()] == '/') 
				flag[i] = false;    
		}        
		for (int i = 0; i < list.size();++i)      
		if (flag[i]) cout << "mkdir -p " << list[i] << endl;
		cout << endl;   
	}    
	return 0;
}