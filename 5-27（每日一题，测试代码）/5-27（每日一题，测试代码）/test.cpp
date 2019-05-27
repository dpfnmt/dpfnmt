#include<iostream>
#include<map>
using namespace std;

void test_map1()
{
	std::map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(5, 5));
	m.insert(make_pair(4, 4));

	std::map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		//cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;
}

//void test_map2()
//{
//	std::string strs[] = { "Æ»¹û", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Î÷¹Ï", "²İİ®", "²İİ®", "Ïã½¶", "Æ»¹û", "Æ»¹û", "Ïã½¶", "Ïã½¶", "Æ»¹û", "Æ»¹û" };
//	std::map<std::string, int> countmap;
//	for (const auto& e : strs)
//	{
//		//std::map<std::string, int>::iterator it = countmap.find(e);
//		auto it = countmap.find(e);
//		if (it != countmap.end())
//		{
//			it->second++;
//		}
//		else
//		{
//			countmap.insert(make_pair(e, 1));
//		}
//	}
//
//	//std::map<std::string, int>::iterator cit = countmap.begin();
//	auto cit = countmap.begin();
//	while (cit != countmap.end())
//	{
//		cout << cit->first << ":" << cit->second << endl;
//		++cit;
//	}
//	cout << endl;
//}

//void test_map3()
//{
//	std::string strs[] = { "Æ»¹û", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Î÷¹Ï", "²İİ®", "²İİ®", "Ïã½¶", "Æ»¹û", "Æ»¹û", "Ïã½¶", "Ïã½¶", "Æ»¹û", "Æ»¹û" };
//	std::map<std::string, int> countmap;
//	for (const auto& e : strs)
//	{
//		//std::pair<std::map<std::string, int>::iterator, bool> ret = countmap.insert(make_pair(e, 1));
//		auto ret = countmap.insert(make_pair(e, 1));
//		if (ret.second == false)
//		{
//			ret.first->second++;
//		}
//	}
//
//	//std::map<std::string, int>::iterator cit = countmap.begin();
//	auto cit = countmap.begin();
//	while (cit != countmap.end())
//	{
//		cout << cit->first << ":" << cit->second << endl;
//		++cit;
//	}
//	cout << endl;
//}

//void test_map4()
//{
//	std::string strs[] = { "Æ»¹û", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Î÷¹Ï", "²İİ®", "²İİ®", "Ïã½¶", "Æ»¹û", "Æ»¹û", "Ïã½¶", "Ïã½¶", "Æ»¹û", "Æ»¹û" };
//	std::map<std::string, int> countmap;
//	for (const auto& e : strs)
//	{
//		countmap[e]++;
//	}
//
//	for (const auto& e : countmap)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}
//
//	std::map<std::string, std::string> dict;
//	dict.insert(std::make_pair("left", "×ó±ß"));
//	dict.insert(std::make_pair("left", "Ê£Óà"));
//	dict["left"] = "Ê£Óà";
//	dict["string"];
//	dict["set"] = "¼¯ºÏ";
//}

int main()
{
	test_map1();

	//test_map2();
	//test_map4();

	return 0;
}

//
//int main() {
//	int N;    cin >> N;          
//	// a, b, b, b    
//	// 0, 1, 1, 2    
//	int a = 0, b = 1;   
//	while(N > b)
//	{        
//		int tmp = a;        
//		a = b;       
//		b += tmp;    
//	}          
//	//cout<<"a= "<<a<<" b = "<<b<<endl;    
//	cout<<min(N-a, b-N)<<endl;          
//	return 0;
//}

//
//int Fibonacci(int N)
//{ 
//	if (N == 0)        
//		return 0;    
//	else if (N == 1)        
//		return 1;    
//	else        
//		return Fibonacci(N - 1) + Fibonacci(N - 2); 
//} 
//int main()
//{
//	int N;    
//	cin >> N;    
//	int num = 0;
//	for (int i = 0; i < 100000; i++)    
//	{        
//		if (Fibonacci(i) - N > 0)        
//		{            
//			num = i;            
//			break;       
//		}   
//	} 
//	if (Fibonacci(num) - N < N - Fibonacci(num - 1))        
//		cout << Fibonacci(num) - N;    
//	else        
//		cout << N - Fibonacci(num - 1);   
//	return 0;
//}