#include<iostream>
#include<vector>
using namespace std;
//
//class Date;
//class Time
//{
//	friend class Date;
//public:
//	Time(int hour = 12, int minute= 38, int second = 48)
//		:_hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	Date(int year = 1990, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << _year <<"-"<< _month <<"-"<< _day << endl;
//	}
//	void SetTimeofDate(int hour, int minute, int second)
//	{
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//		_t._minute = minute;
//		cout << _t._hour << "-" << _t._minute << "-" << _t._second << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//int main()
//{
//	Date d1(2019,4,8);
//	//d1.SetTimeofDate(12,45,32);
//	return 0;
//}

//class A
//{
//private:
//	static int k;
//	int a =20;
//public:
//	class B
//	{
//	public:
//		void fun(const A& b)
//		{
//			cout << k << endl;
//			cout <<b.a << endl; //这里就不能直接访问，需要使用类名调用；
//		}
//
//	};
//};
//
//int A::k = 10;
//
//int main()
//{
//	A::B b;
//	b.fun(A());
//	return 0;
//}

//int main()
//{
//	vector<int> frist;
//	vector<int> second(4,100);
//	vector<int> theer(second.begin(),second.end());
//	vector<int> four(theer);
//
//	return 0;
//}


//void vectorPrint(const vector<int>& v)   //使用const迭代器进行打印
//{
//	vector<int>::const_iterator it = v.cbegin();
//	while (it != v.cend())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(5);
//	v.push_back(6);
//
//	vector<int>::iterator it = v.begin();   //使用迭代器进行打印
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	it = v.begin();           //使用迭代器进行修改
//	while (it != v.end())
//	{
//		*it *= 2;
//		++it;
//	}
//	cout << endl;
//
//
//	vector<int>::reverse_iterator rit = v.rbegin();  //反向迭代器的遍历并且打印
//	while (rit !=v.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//	vectorPrint(v);
//	return 0;
//}

//int main()    // capacity
//{
//	size_t sz;
//	vector<int> fun;
//	sz = fun.capacity();
//	for (int i = 0; i < 100; i++)
//	{
//		fun.push_back(i);
//		if (sz != fun.capacity())
//		{
//			sz = fun.capacity();
//			cout << "capacity change" << sz << endl;
//		}
//	}
//
//	return 0;
//}


//int main()
//{
//	size_t sz;
//	vector<int> fun;
//	sz = fun.capacity();
//	for (int i = 0; i < 100; i++)
//	{
//		fun.push_back(i);
//		if (sz != fun.capacity())
//		{
//			sz = fun.capacity();
//			cout << "capacity change 1 " << sz << endl;
//		}
//	}
//
//
//	size_t s;
//	vector<int> bar;
//	s = bar.capacity();
//	bar.reserve(100);
//	for (int i = 0; i < 100; i++)
//	{
//		bar.push_back(i);
//		if (s != bar.capacity())
//		{
//			s = bar.capacity();
//			cout << "capacity change 2 " << s << endl;
//		}
//	}
//	return 0;
//}


//int main()
//{
//	vector<int> v1;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	v1.resize(5);
//	v1.resize(10,20);
//	v1.resize(12);
//	for (size_t i = 0; i < v1.size(); i++)
//	{
//		cout << " " << v1[i];
//		cout << "\n";
//	}
//	return 0;
//}


//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	v.pop_back();
//	v.pop_back();
//
//	it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//	 v.insert(pos ,30);
//
//		vector<int>::iterator it = v.begin();
//		while (it != v.end())
//		{
//			cout << *it << " ";
//			it++;
//		}
//		cout << endl;
//
//		pos = find(v.begin(), v.end(), 3);
//
//		v.erase(pos);
//		vector<int>::iterator ite = v.begin();
//		while (ite != v.end())
//		{
//			cout << *ite << " ";
//			++ite;
//		}
//
//
//	return 0;
//}

//#include<i>
//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	v[0] = 10;
//	cout << v[0] << endl;
//	
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//
//	vector<int> swapv;
//	swapv.swap(v);
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//	cout << "v data";
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//
//	cout << "swapv data";
//
//	for (auto x : v)
//	{
//		cout << x<<" ";
//	}
//	cout << "swapv data";
//	cout << endl;
//
// 	return 0;
//}

//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//
//	    //回答一
//	    v.erase(pos);
//		cout << *pos << endl;
//
//		//回答二
//		pos = find(v.begin(), v.end(), 3);
//		v.insert(pos,30);
//        cout << *pos << endl;
//		
//
//	return 0;
//}

//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//		{
//			v.erase(it);
//			++it;
//		}
//		cout << endl;
//	}
//	return 0;
//}

int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else
		{
			it++;
		}
	}
	cout << endl;
	return 0;
}