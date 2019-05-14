#include<iostream>
#include<vector>
using namespace std;

template<class T>
class SmartPtr {
public:
	SmartPtr(T* ptr)
		: _ptr(ptr)
	{}
	~SmartPtr()
	{
		cout << _ptr << endl;
		delete[] _ptr;
	}
private:
	T* _ptr;
};

void func()
{
	int* p = new int;
	SmartPtr<int> sp1(p);

	//vector<int> v;  //这里还没有使用智能指针，会出现内存没有释放，
	//v.at(0) = 10;

	vector<int> v(10);
	size_t pos;
	cin >> pos;
	v.at(pos) = 10;
}
int main()
{
	try{
		func();

	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}