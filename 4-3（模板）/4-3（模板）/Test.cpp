#include<iostream>
using namespace std;

//void Swap(int& a, int& b)
//{
//	int tmp = a;
//	 a = b;
//	 b = tmp;
//
//}
//void Swap(double& a, double& b)
//{
//	double tmp = a;
//	a = b;
//	b = tmp;
//
//}
//
//void Swap(char& a, char& b)
//{
//	char tmp = a;
//	a = b;
//	b = tmp;
//
//}
//template<typename T>
//void Swap(T& a, T& b)
//{
//	T tmp = a;
//		a = b;
//		b = tmp;
//}
//int main()
//{
//	int g =3;
//	int h = 2;
//	Swap(g, h);
//	cout << g << endl;
//	cout << h << endl;
//	double i = 3.45;
//	double j = 2.34;
//	Swap(i, j);
//	cout << i << endl;
//	cout << j << endl;
//
//	return 0;
//}

//template<class T>
//T Add(const T& a , const T& b)
//{
//	return a + b;
//}
//
//int main()
//{
//	/*int a = 10;
//	int b = 20;
//	Add(a, b);
//	cout << Add(a, b) << endl;
//
//	double a1 = 10.34;
//	double b2 = 20.45;
//	Add(a1, b2);
//	cout << Add(a1, b2) << endl;*/
//
//	int a = 10;
//	double b = 20.34;
//	Add<int>(a, b);
//	cout << Add<int>(a, b) << endl;
//	return 0;
//}

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//template<class T>
//T Add(const T& a, const T& b)
//{
//	return a + b;
//}
//
//int main()
//{
//	
//	Add(1, 2);
//	Add<int>(3, 4);
//	cout << Add<int>(3, 4) << endl;
//	cout << Add(1, 2) << endl;
//	return 0;
//}

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//template<class T1 , class T2>
//T1 Add( T1 a,  T2 b)
//{
//	return a + b;
//}
//
//int main()
//{
//	
//	Add(1, 2);
//	Add(3.45, 4.34);
//	cout << Add(3.45, 4.34) << endl;
//	cout << Add(1, 2) << endl;
//	return 0;
//}


template<class T>
class Vector
{
public:
	Vector(size_t capacity = 10)
		:_pDate(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}
	~Vector(); // 在类的里面声明，在类的外面实现；
	void PushBack(const T& data)
	{
		_pDate[_size++] = data;
	}
	void PopBack()
	{
		--_size;
	}
	void Print()
	{
		for (int i = 0; i < _size; i++)
		{
			cout << _pDate[i] << endl;
		}
	}
	void Print2()
	{
		for (int i = 0; i < _size; i++)
		{
			cout << _pDate[i] << endl;
		}
	}
	size_t size()
	{
		return _size;
	}
	T& operator[](size_t pos)
	{
		assert(pos < _size);
		return _pDate[pos];
	}
private:
	T* _pDate;
	size_t _size;
	size_t _capacity;
};

template<class T>
Vector<T>::~Vector()
{
	if (_pDate)
	{
		delete[] _pDate;
	}
}

int main()
{
	Vector<int> v1;
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);
	v1.PushBack(5);
	v1.Print();
	v1.PopBack();
	v1.Print();
	v1.size();
	v1.Print();

	Vector<double> v2;
	v2.PushBack(1.23);
	v2.PushBack(2.34);
	v2.PushBack(3.45);
	v2.PushBack(4.56);
	v2.PushBack(5.67);
	v2.Print2();
	v2.PopBack();
	v2.Print2();
	v2.size();
	v2.Print2();
	return 0;
}