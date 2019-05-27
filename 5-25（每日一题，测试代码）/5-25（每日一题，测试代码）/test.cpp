#include<iostream>
using namespace std;
//
//int main()
//{ 
//	int n, curSum = 0, maxSum = -1e5;    
//	cin >> n;    
//	int arr[n];
//	for (int i = 0; i<n; i++)
//	{ 
//		cin >> arr[i];        
//		curSum += arr[i];        
//		if (curSum>maxSum)
//		{ 
//			maxSum = curSum; 
//		}        
//		if (curSum < 0)
//		{ 
//			curSum = 0; 
//		} 
//	}    
//	cout << maxSum << endl;    
//	return 0;
//}
#include<string>
#include<vector>

bool IsCricle(const string& str)
{
	size_t begin = 0;
	size_t end = str.size() - 1;
	while (begin < end)
	{
		if (str[begin] != str[end])
			return false;
		++begin;
		--end;
	}
	return true;
}
int main()
{
	string str1;
	string str2;
	getline(cin, str1);
	getline(cin, str2);
	size_t count = 0;
	for (size_t i = 0; i <= str1.size(); i++)
	{
		string str = str1;
		str.insert(i, str2);
		if (IsCricle(str))
			++count;
	}
	cout << count << endl;
	return 0;
}

