#include<iostream>

using namespace std;

int main()
{
	cout << " hello world " << endl;
	return 0;
}

#include <iostream>
using namespace std;

class Person{
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
};

class Student : public Person {
public:
	virtual void BuyTicket() { cout << "买票-半价" << endl; }
};

void Func(Person& p)
{
	p.BuyTicket();
}

int main()
{
	Person Mike;
	Func(Mike);
	Student Johnson;
	Func(Johnson);
	return 0;
}

//class Base1 {
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int b1;
//};
//
//class Base2 {
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private:
//	int b2;
//};
//
//class Derive : public Base1, public Base2 {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int d1;
//};
//
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[])
//{
//	cout << " 虚表地址>" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i)
//	{
//		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
//		VFPTR f = vTable[i];
//		f();
//	}
//	cout << endl;
//}
//
//#include <fstream>
//
//int main()
//{
//	//cout << sizeof(Derive) << endl;
//	//Derive d;
//	//PrintVTable((VFPTR*)(*(int*)&d));
//	//PrintVTable((VFPTR*)(*(int*)((char*)&d+sizeof(Base1))));
//
//	FILE* fout = fopen("test.txt", "r");
//	if (fout == nullptr)
//	{
//		cout << errno << endl;
//	}
//
//	ifstream ifs;
//	ifs.open("test.txt");
//
//	return 0;
//}

#include <string>

//void Func2()
//{
//	throw 1.11111;
//
//	throw 5;
//}
//
//void Func1()
//{
//	try
//	{
//		Func2();
//	}
//	catch (int i)
//	{
//		cout << i << endl;
//	}
//
//	FILE* fout = fopen("test.txt", "r");
//	if (fout == nullptr)
//	{
//		string errmsg("打开文件失败");
//		throw errmsg;
//	}
//
//	cout << "Func2" << endl;
//}
//
//int main()
//{
//	try
//	{
//		Func1();
//	}
//	catch (string& s)
//	{
//		cout << s << endl;
//	}
//	catch (int i)
//	{
//		cout << i << endl;
//	}
//	catch (...)
//	{
//		cout << "未知异常" << endl;
//	}
//
//	return 0;
//}

//double Division(int a, int b) throw (const char*)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//
//void Func()
//{
//	int* array = new int[10];
//	//int* array2 = new int[20];
//	//int* array3 = new int[20];
//	//int* array4 = new int[20];
//	try
//	{
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (...)
//	{
//		cout << "delete:" << array << endl;
//		delete[] array;
//		throw;
//	}
//
//	// ...
//
//	delete[] array;
//	cout << "delete:" << array << endl;
//}
//
//int main()
//{
//	try {
//		Func();
//	}
//	catch (const char* errmsg){
//		cout << errmsg << endl;
//	}
//	catch (...){
//		cout << "unkown exception" << endl;
//	}
//	return 0;
//}

//int main()
//{
//	try
//	{
//		string s("hello");
//		cout << s.at(7) << endl;
//
//		char* p1 = new char[0x7fffffff];
//		cout << p1 << endl;
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//}

//class BitException
//{
//public:
//	BitException(int errid, string errmsg, string file, int line)
//		:_errid(errid)
//		, _errmsg(errmsg)
//		, _file(file)
//		, _line(line)
//	{}
//
//protected:
//	int _errid;
//	string _errmsg;
//	string _file;
//	int _line;
//
//	//stack<string> _funcst; // 函数堆栈
//};
//
//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		BitException e(1, "除0错误", __FILE__, __LINE__);
//		throw e;
//	}
//	return (double)a / (double)b;
//}
//
//int main()
//{
//	try
//	{
//	/*	int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;*/
//		cout << string() << endl;
//	}
//	catch (const BitException& e)
//	{
//		int i = 0;
//	}
//	catch (...)
//	{
//	}
//}


//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		throw "除0错误";
//	}
//	return (double)a / (double)b;
//}
//
//template<class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//
//	~SmartPtr()
//	{
//		cout << "delete:" << _ptr << endl;
//		delete[] _ptr;
//	}
//private:
//	T* _ptr;
//};
//
//int main()
//{
//	try
//	{
//		int* array = new int[10];
//		SmartPtr<int> sp(array);
//
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (const char* str)
//	{
//		cout << str << endl;
//	}
//	catch (...)
//	{
//	}
//}
