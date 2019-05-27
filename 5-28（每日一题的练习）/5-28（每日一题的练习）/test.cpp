//#include<iostream>
//#include<string>
//#include<vector>
//
//using namespace std;
//
//vector<string>  v;  
////按照字典序排序
//bool  lexicographically()
//{     
//	int i=0;    
//	string s;     
//	while((i+1) < v.size())
//	{        
//		if(v[i].compare(v[i+1]) >0)  //这里的compare是什么意思，还没有懂。          
//			return 0;        
//		i++;    
//	}    
//	return 1;
//} 
////按照字符串大小排序
//bool Lenths()
//{     
//	int i=0;    
//	while((i+1) <v.size() )
//	{        
//		if(v[i+1].size() < v[i].size() )            
//			return 0;       
//		    i++;    
//	}    
//	return 1;
//}
//int main()
//{     
//	string s;    
//	int n,i=0;    
//	bool b1,b2;     
//	cin>>n;    
//	while(i < n)
//	{        
//		cin>>s;        
//		v.push_back(s);        
//		i++;    
//	}     
//	b1=lexicographically();    
//	b2=Lenths();     
//	if(b1 && b2)       
//		cout<<"both";    
//	else if(b1 && !b2)        
//		cout<<"lexicographically";    
//	else if(!b1 && b2)        
//		cout<<"lengths";    
//	else        
//		cout<<"none";      
//	return 0;
//}

#include<iostream>
using namespace std;


//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	int max = a > b ? a : b;
//	for (int i = max; i < a * b; i++)
//	{
//		if (i % a == 0 && i % b == 0)
//		{
//			cout << i;
//			break;
//		}
//	}
//	return 0;
//}

#include<string>
#include<map>
//
//void test_map1()
//{
//	std::map<int, int> m;
//	m.insert(make_pair(1, 1));
//	m.insert(make_pair(3, 3));
//	m.insert(make_pair(2, 2));
//	m.insert(make_pair(5, 5));
//	m.insert(make_pair(4, 4));
//
//	std::map<int, int>::iterator it = m.begin();
//	while (it != m.end())
//	{
//		cout << (*it).first << ":" << (*it).second << endl;
//		//cout << it->first << ":" << it->second << endl;
//		++it;
//	}
//	cout << endl;
//}
//
//int main()
//{
//	test_map1();
//	return 0;
//}