//#include <iostream>
//#include <vector>
//#include <numeric>
//#include <limits>
//
//#include <functional> 
//#include <algorithm> 
//using namespace std;
//
//vector < int > arraySort(vector < int > arr)
//{
//	/*for (int i = 0; i < arr.size() - 1; i++)
//	{
//		for (int j = 0; j < arr.size() - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//	return arr;*/
//	sort(arr.begin(), arr.end(), less<int>());
//	return ;
//}
//
//int main() {
//	vector < int > res;
//
//	int _arr_size = 0;
//	cin >> _arr_size;
//	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//	vector<int> _arr;
//	int _arr_item;
//	for (int _arr_i = 0; _arr_i<_arr_size; _arr_i++) {
//		cin >> _arr_item;
//		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//		_arr.push_back(_arr_item);
//	}
//
//
//
//	res = arraySort(_arr);
//	for (int res_i = 0; res_i < res.size(); res_i++) {
//		cout << res[res_i] << endl;;
//	}
//
//	return 0;
//
//}

#include <algorithm>
#include <iostream>
#include<functional>
#include<vector>
using namespace std; 
vector<int> bubble_sort(vector<int> v)
{	
	for(int i = 0; i < v.size() - 1; i ++)		
	for (int j = 0; j < v.size() - 1 - i; j++)		
	{			
		if (v[j] > v[j + 1]) 	
		{				
			int temp = v[j];		
			v[j] = v[j + 1];		
			v[j + 1] = temp;		
		}		
	}	
	return v;
}
int main()
{	
		int n;	cout << "请输入要进行冒泡排序的个数n : ";	
		cin >> n;	
		vector<int> v(n);	
		cout << "请输入 n 个数： ";	
		for (int i = 0; i < n; i++)		
			cin >> v[i];	
			vector<int> v2 = bubble_sort(v);	
			cout << "经过冒泡排序后的结果是: ";	
			for (int i = 0; i < v2.size(); i++)		
				cout << v2[i] << " ";	
			cout << endl;	
			return 0;
}
	
