#include<iostream>
#include<string>
#include<list>

using namespace std;


//int main()
//{
//	list<int> l1;                                //构造空的l1;
// 	list<int> l2(4,100);                         //l2中放4个值为100的数；
//	list<int> l3(l2.begin(),l2.end());           //用l2的左右区间开辟l3；
//	list<int> l4(l3);                            //用l3拷贝构造l4；
//
//	int arr[] = { 1, 9, 7,5 };
//	list<int> l5(arr, arr + sizeof(arr) / sizeof(int));
//
//	//使用迭代器打印l5中的成员
//	for (list<int>::iterator it = l5.begin(); it != l5.end(); ++it)
//		cout << *it << " ";
//		cout << endl;
//
//		for (auto&e : l5)
//		{
//			cout << e << " ";
//		}
//		cout << endl;
//
//
//	return 0;
//}


//int main()
//{
//	int arr[] = { 1, 2, 3, 5, 6, 9, 8, 7, 4, 0 };
//	list<int> l(arr, arr + sizeof(arr) / sizeof(int));
//
//	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//
//	for (auto& e : l)
//	{
//		cout << e << " ";
//     }
//	cout << endl;
//
//	//反向迭代器
//	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it)
//		cout << *it << " ";
//	    cout << endl;
//	return 0;
//}


//int main()
//{
//	int arr[] = { 1, 2, 3, 5, 6, 9, 8, 7, 4, 0 };
//	list<int> l(arr, arr + sizeof(arr) / sizeof(int));
//
//	//答应该字符里面的个数
//	cout << l.size() << endl;
//
//	//判断是否为空
//	if (l.empty())
//	{
//		cout << "list = nullptr" << endl;
//	}
//	else
//	{
//		for (auto& e : l)
//		{
//			cout << e << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1, 2, 3, 5, 6, 9, 8, 7, 4, 0 };
//	list<int> l(arr, arr + sizeof(arr) / sizeof(int));
//
//	 l.front() = 10;
//	 l.back() = 10;
//	 
//		for (auto& e : l)
//		{
//			cout << e << " ";
//		}
//		cout << endl;
//
//		const list<int> l1(arr, arr + sizeof(arr) / sizeof(int));
//		int&cl = l1.front(); //这里会报错，我们可以看上面为const的类型，所以我们需要使用const; 
//
//		const int&cl = l1.front(); //我们可以看到，这里可以编过；
//
//	return 0;
//}



//int main()
//{
//	int arr[] = { 1, 2, 3, 5, 6, 9, 8, 7, 4, 0 };
//	list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
//	/*auto it = l.begin();
//	while (it != l.end())
//	{
//	l.erase(it);   //erase()执行之后，it节点已经释放了，在访问it时，已经无效了。所以应该先先给赋值
//	++it;
//	}
//	cout << endl;*/
//
//	auto it = l.begin();
//	while (it != l.end())
//	{
//		l.erase(it++);   //注意：这里是后置++，使用前置++，程序崩溃，找不到前面的那个；
//	}
//	cout << endl;
//	return 0;
//}
