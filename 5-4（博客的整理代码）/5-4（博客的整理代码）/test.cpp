#include<iostream>
#include<string>
#include <memory>
#include <thread>
#include <mutex>
using namespace std;

//
//int main()
//{
//	try
//	{
//		char* p = new char[0x7fffffff];
//		cout << (void*)p << endl;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (int i)
//	{
//		cout << i << endl;
//	}
//	return 0;
//}

//void func1()
//{
//	//throw 10;//����func1�ˣ�Ȼ��ֱ������ˡ�
//
//	throw 10.12909;//���������쳣
//}
//void func2()
//{
//	try
//	{
//		string str("error");
//	    throw str;
//	}
//	catch (const string& str)
//	{
//		cout << str << endl;
//	}
//}
//int main()
//{
//	try
//	{
//		func1();
//		func2();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (int i)//���������쳣
//	{
//		cout << i << endl;
//	}
//	catch (const string& str)//����string�쳣
//	{
//		cout << str << endl;
//	}
//	catch(...) //���������쳣��֪�������쳣�����ǲ�֪������ʲô�쳣��
//	{
//		cout << "δ֪�쳣" << endl;
//	}
//	cout << "end" << endl;
//	return 0;
//}

//�����³�������ʾ

//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
////void Func()
////{
////	//����������������ʱ��
////	int* p = new int[10];
////
////	int len, time;
////	cin >> len >> time;
////	cout << Division(len, time) << endl;
////      
////	delete[] p; //���ﵱ��ĸΪż����ʱ����ô�Ͳ��ܱ���Ч���ͷ��ˣ�������������Ҫ�Լ��ػ��쳣��
////	cout << p << endl;
////}
//void Func()
//{
//	//����������������ʱ��
//	int* p = new int[10];   //�쳣��ȫ����
//	try{
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	//��һ�ֽ��
//	//catch (const char* errmsg)
//	//{
//	//	delete[] p; //���ﵱ��ĸΪż����ʱ����ô�Ͳ��ܱ���Ч���ͷ��ˣ�������������Ҫ�Լ��ػ��쳣��
//	//	cout << p << endl;
//	//	throw errmsg;
//	//}
//	//�ڶ��ֽ��������֪��ʲô�쳣��ʱ��
//	catch (...)
//	{
//		delete[] p;
//		cout << p << endl;
//		throw;
//	}
//	delete[] p;  //���ֻ��������Ļ���ֻ�ͷţ�����û���׳��쳣����������ܴ󣬲��ܸ������洦����ˣ�
//	cout << p << endl;
//}
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (...)
//	{
//		cout << "unkown exception" << endl;
//	}
//	return 0;
//}


//void test_auto_ptr()
//{
//	auto_ptr<int> ap(new int);
//	*ap = 10;
//	cout << *ap << endl;
//
//	auto_ptr<int> copy(ap);
//	cout << *ap << endl;
//	cout << *copy << endl;
//}
//
//void test_unique_ptr()
//{
//	unique_ptr<int> up(new int);
//	*up = 10;
//	cout << *up << endl;
//
//	//unique_ptr<int> copy(up);
//	//cout << *ap << endl;
//	//cout << *copy << endl;
//}
//
//void test_shared_ptr()
//{
//	shared_ptr<int> sp(new int);
//	*sp = 10;
//	cout << *sp << endl;
//
//	shared_ptr<int> copy(sp);
//	cout << *sp << endl;
//	cout << *copy << endl;
//}
//
//namespace BIT
//{
//	template<class T>
//	class AutoPtr
//	{
//	public:
//		AutoPtr(T* ptr)
//			:_ptr(ptr)
//		{}
//
//		~AutoPtr()
//		{
//			if (_ptr)
//			{
//				cout << "delete:" << _ptr << endl;
//				delete _ptr;
//			}
//		}
//
//
//		// BIT::AutoPtr<int> copy(ap);
//		AutoPtr(AutoPtr<T>& ap)
//		{
//			_ptr = ap._ptr;
//			ap._ptr = nullptr;
//		}
//
//		T& operator*()
//		{
//			return *_ptr;
//		}
//
//		T* operator->()
//		{
//			return _ptr;
//		}
//	private:
//		T* _ptr;
//	};
//
//	template<class T>
//	class UniquePtr
//	{
//	public:
//		UniquePtr(T* ptr)
//			:_ptr(ptr)
//		{}
//
//		~UniquePtr()
//		{
//			if (_ptr)
//			{
//				cout << "delete:" << _ptr << endl;
//				delete _ptr;
//			}
//		}
//
//		T& operator*()
//		{
//			return *_ptr;
//		}
//
//		T* operator->()
//		{
//			return _ptr;
//		}
//
//		// C++11 ������
//		//UniquePtr(UniquePtr<T>& ap) = delete;
//	private:
//		// ������ C++98 1.ֻ������ʵ�� 2.˽��
//		UniquePtr(UniquePtr<T>& ap);
//	private:
//		T* _ptr;
//	};
//
//	template<class T>
//	class SharedPtr
//	{
//	public:
//		SharedPtr(T* ptr)
//			:_ptr(ptr)
//			, _pcount(new int(1))
//			, _pmtx(new mutex)
//		{}
//
//		~SharedPtr()
//		{
//			/*if (--(*_pcount) == 0)
//			{
//			cout << "delete:" << _ptr << endl;
//			delete _ptr;
//			delete _pcount;
//			}*/
//
//			Realase();
//		}
//
//		SharedPtr(const SharedPtr<T>& sp)
//			:_ptr(sp._ptr)
//			, _pcount(sp._pcount)
//			, _pmtx(sp._pmtx)
//		{
//			//++(*_pcount);
//			AddRefCount();
//		}
//
//		// sp1 = sp2
//		SharedPtr<T>& operator=(const SharedPtr<T>& sp)
//		{
//			//if (this != &sp)
//			if (_ptr != sp._ptr)
//			{
//				/*if (--(*_pcount) == 0)
//				{
//				delete _ptr;
//				delete _pcount;
//				}*/
//
//				Realase();
//
//				_ptr = sp._ptr;
//				_pcount = sp._pcount;
//				//++(*_pcount);
//				AddRefCount();
//			}
//
//			return *this;
//		}
//
//		void AddRefCount()
//		{
//			_pmtx->lock();
//			++(*_pcount);
//			_pmtx->unlock();
//		}
//
//		void Realase()
//		{
//			bool deleteflag = false;
//			_pmtx->lock();
//			if (--(*_pcount) == 0)
//			{
//				cout << "delete" << _ptr << endl;
//				delete _pcount;
//				delete _ptr;
//				deleteflag = true;
//			}
//			_pmtx->unlock();
//
//			if (deleteflag == true)
//				delete _pmtx;
//		}
//
//		T& operator*()
//		{
//			return *_ptr;
//		}
//
//		T* operator->()
//		{
//			return _ptr;
//		}
//
//		int use_count()
//		{
//			return *_pcount;
//		}
//
//	private:
//		T* _ptr;
//		int* _pcount;
//		mutex* _pmtx;
//	};
//}
//
//void TestAutoPtr()
//{
//	BIT::AutoPtr<int> ap(new int);
//	BIT::AutoPtr<int> copy(ap);
//}
//
//void TestUniquePtr()
//{
//	BIT::UniquePtr<int> ap(new int);
//	//BIT::UniquePtr<int> copy(ap);
//}
//
//void TestSharedPtr()
//{
//	BIT::SharedPtr<int> sp(new int);
//	BIT::SharedPtr<int> copy(sp);
//
//	BIT::SharedPtr<int> sp1(new int);
//	BIT::SharedPtr<int> sp2(sp1);
//
//	//sp = sp1;
//	//copy = sp1;
//
//	sp1 = sp1;
//	sp1 = sp2;
//}
//
//int main()
//{
//	//test_auto_ptr();
//	//test_shared_ptr();
//	//TestAutoPtr();
//	//TestUniquePtr();
//	TestSharedPtr();
//
//	return 0;
//}