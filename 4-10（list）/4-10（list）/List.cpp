#include<iostream>
#include<string>
#include<list>

using namespace std;


//int main()
//{
//	list<int> l1;                                //����յ�l1;
// 	list<int> l2(4,100);                         //l2�з�4��ֵΪ100������
//	list<int> l3(l2.begin(),l2.end());           //��l2���������俪��l3��
//	list<int> l4(l3);                            //��l3��������l4��
//
//	int arr[] = { 1, 9, 7,5 };
//	list<int> l5(arr, arr + sizeof(arr) / sizeof(int));
//
//	//ʹ�õ�������ӡl5�еĳ�Ա
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
//	//���������
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
//	//��Ӧ���ַ�����ĸ���
//	cout << l.size() << endl;
//
//	//�ж��Ƿ�Ϊ��
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
//		int&cl = l1.front(); //����ᱨ�����ǿ��Կ�����Ϊconst�����ͣ�����������Ҫʹ��const; 
//
//		const int&cl = l1.front(); //���ǿ��Կ�����������Ա����
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
//	l.erase(it);   //erase()ִ��֮��it�ڵ��Ѿ��ͷ��ˣ��ڷ���itʱ���Ѿ���Ч�ˡ�����Ӧ�����ȸ���ֵ
//	++it;
//	}
//	cout << endl;*/
//
//	auto it = l.begin();
//	while (it != l.end())
//	{
//		l.erase(it++);   //ע�⣺�����Ǻ���++��ʹ��ǰ��++������������Ҳ���ǰ����Ǹ���
//	}
//	cout << endl;
//	return 0;
//}
