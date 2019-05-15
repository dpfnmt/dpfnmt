//#include<iostream>
//
//using namespace std;

//int main()
//{
//	cout << "hello world"<<endl;
//	return 0;
//}

//#include <memory>

//int main() {
//	std::auto_ptr<int> p1(new int(10));
//	std::auto_ptr<int> p2(new int);
//
//	*p2 = *p1 * 3;
//
//	std::cout << "p1 points to: " << *p1 << '\n';
//	std::cout << "p2 points to: " << *p2 << '\n';
//
//	return 0;
//}


//int main()
//{
	/*
	std::auto_ptr<int> p1(new int);
	*p1.get() = 10;

	std::auto_ptr<int> p2(p1);

	std::cout << "p2 points to " << *p2 << '\n';*/
	// (p1 is now null-pointer auto_ptr)
//
//	std::default_delete<int> d;
//	std::unique_ptr<int> u1;
//	std::unique_ptr<int> u2(nullptr);
//	std::unique_ptr<int> u3(new int);
//	std::unique_ptr<int> u4(new int, d);
//	std::unique_ptr<int> u5(new int, std::default_delete<int>());
//	std::unique_ptr<int> u6(std::move(u5));
//	std::unique_ptr<int> u7(std::move(u6));
//	std::unique_ptr<int> u8(std::auto_ptr<int>(new int));
//
//	std::cout << "u1: " << (u1 ? "not null" : "null") << '\n';
//	std::cout << "u2: " << (u2 ? "not null" : "null") << '\n';
//	std::cout << "u3: " << (u3 ? "not null" : "null") << '\n';
//	std::cout << "u4: " << (u4 ? "not null" : "null") << '\n';
//	std::cout << "u5: " << (u5 ? "not null" : "null") << '\n';
//	std::cout << "u6: " << (u6 ? "not null" : "null") << '\n';
//	std::cout << "u7: " << (u7 ? "not null" : "null") << '\n';
//	std::cout << "u8: " << (u8 ? "not null" : "null") << '\n';
//	return 0;
//}

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
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//private:
//	T* _ptr;
//};
//
//struct AA
//{
//	int _a1;
//	int _a2;
//};
//
//int main()
//{
//	//int* p = new int(1);
//	SmartPtr<int> sp(new int(10));
//	SmartPtr<int> copy(sp);
//
//	/**p = 2;
//	*sp = 20;
//	sp.operator*() = 20;
//	cout << *sp << endl;
//
//	SmartPtr<AA> spaa(new AA);
//	(*spaa)._a1 = 10;
//	spaa->_a2 = 20;
//
//	spaa.operator->()->_a1 = 100;
//
//	cout << spaa->_a1 << endl;
//	cout << spaa->_a2 << endl;*/
//
//	return 0;
//}
//#include<iostream>
//#include <memory>
//#include <thread>
//#include <mutex>
//
//using namespace std;


////c++98 auto_ptr  管理权转移，设计缺陷，严谨使用，
//void test_auto_ptr()//一般不采取这个，问题不能被好的解决。
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
////c++11 防止拷贝，简单粗暴的设计，鼓励使用
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
////c++11 引用计数，支持拷贝，鼓励使用
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
//int main()
//{
//	//test_auto_ptr();
//	//test_unique_ptr();
//	test_shared_ptr();
//
//	return 0;
//}
//namespace DPF
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
//		// C++11 防拷贝
//		//UniquePtr(UniquePtr<T>& ap) = delete;
//	private:
//		// 防拷贝 C++98 1.只声明不实现 2.私有
//		UniquePtr(UniquePtr<T>& ap);
//	private:
//		T* _ptr;
//	};
//
//	template<class T>
//	class SharedPtr    //引用计数
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
//			//if (this != &sp)  //遇到自己给自己赋值的情况
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
//				AddRefCount();//代替上面注销部分，以上代码也是这样。
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
//	DPF::AutoPtr<int> ap(new int);
//	DPF::AutoPtr<int> copy(ap);
//}
//
//void TestUniquePtr()
//{
//	DPF::UniquePtr<int> ap(new int);
//	//DPF::UniquePtr<int> copy(ap);//防止拷贝的
//}
//
//void TestSharedPtr()
//{
//	DPF::SharedPtr<int> sp(new int);
//	DPF::SharedPtr<int> copy(sp);
//
//	DPF::SharedPtr<int> sp1(new int);
//	DPF::SharedPtr<int> sp2(sp1);
//
//	sp = sp1;
//	copy = sp1;
//
//	//sp1 = sp1;
//	//sp1 = sp2;
//}
//
//int main()
//{
//	//TestAutoPtr();
//	//TestUniquePtr();
//	TestSharedPtr();
//
//	return 0;
//}

#include<iostream>
#include <memory>
#include <thread>
#include <mutex>

using namespace std;


template<class lock>
class UnipueLock
{
public:
	UnipueLock(lock& lock)
	:_lock(lock)
	{
		_lock.lock();
	}
	~UnipueLock()
	{
		_lock.unlock();
	}
private:
	lock& _lock;//成员变量给的是引用。
};

int main()
{
	mutex mtx;
	UnipueLock<mutex> lock(mtx);

	return 0;
}