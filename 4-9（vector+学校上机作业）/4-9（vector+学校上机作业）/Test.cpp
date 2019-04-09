#include<iostream>
#include<string>
#include<assert.h>
using namespace std;


namespace dpf
{
	template<class T>
	class Vector
	{
	public:
		typedef T* iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		


		Vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofStorage(nullptr)
		{}

		Vector(const Vector<int>& v)
		{
			_start = new T[v.Capacity()];
			for (size_t i = 0; i < v.Size(); ++i)
			{
				_start = v[i];
			}
			_finish = _start + v.Size();
			_endofStorage = _start + v.Capacity();
		}

		~Vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofStorage = nullptr;
			}
		}

		void Reserve(size_t n)
		{
			if (n > Capacity())  //这里忘记写()了
			{
				size_t size = Size();
				T* tmp = new T[n];

				if (size > 0)
				{
					//memcpy(tmp, _start, sizeof(T)*size); //T它不知道什么类型，这里不知道什么类型的
					for (size_t i = 0; i < size; i++)   //这里相当于string的赋值
					{
						tmp[i] = _start[i];
					}

					delete[] _start;
				}

				_start = tmp;
				_finish = _start + size;
				_endofStorage = _start + n;
			}
		}
		void Resize(size_t n , const T&value = T())
		{
			if (n > Capacity())
			{
				_Reverse(n);
			}
			if (n < Size())
			{
				_finish = _start + n;
			}
			else
			{
				while (_finish < _start + n)
				{
					*_finish = value;
					++_finish;
				}
			}
		}

		size_t Size()  const { return _finish - _start; };
		size_t Capacity()  const { return _endofStorage - _start; };

		T& operator[](size_t pos)
		{
			assert(pos < Size());
			return _start[pos];
		}
		 T& operator[](size_t pos) const 
		{
			assert(pos < Size());
			return _start[pos];
		}
		void PushBack(const T& x)
		{
			Insert(_finish, x);
		}
		void PopBank()
		{
			Erase(_finish - 1); // 这里不能用--(——finish)而要用 (finish-1) ,两者是不一样的
		}
		void Insert(iterator& pos, const T& x)  //这里出现迭代器时效问题 ，要用&
		{
			size_t n = pos - _start;   //释放空间，pos位置找不到，下面加的话，太大了，应该先保存前面的在加。
			if (_finish == _endofStorage)
			{
				size_t newcapacity = Capacity() == 0 ? 2 : Capacity() * 2;   //这里两个都忘记写()了；
				Reserve(newcapacity);
			}

			pos = _start + n;
			iterator end = _finish -1;
			while (end >= pos)
			{
				*(end + 1) = *(end);
				--end;
			}
			*pos = x;
			++_finish;
		}
		void Erase(iterator pos)
		{
			assert(pos < _finish && pos >= _start);
			iterator cur = pos + 1;
			while (cur < _finish)
			{
				*(cur - 1) = *cur;
				++cur;
			}
			--_finish;
		}
	private:
		iterator  _start;  //指向数据块的头
		iterator  _finish; //指向有效数据的尾
		iterator  _endofStorage;    //指向储存容量的尾
	};

	void TestVector()
	{
		Vector<int> v;
		v.PushBack(1);
		v.PushBack(2);
		v.PushBack(3);
		v.PushBack(4);

		for (size_t i = 0; i < v.Size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		//dpf::Vector<int>::iterator it = v.begin();
		auto it = v.begin();   //c++11 适用 
		                       //但是这个有缺陷，不知道前面的类型是什么，比如前面的为const类型也不知道
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (const auto& e : v)  //这里的v为int型，用引用比较好一点
		{
			cout << e << " ";
		}
		cout << endl; 

	}

	void TestVector1()
	{
		Vector<string> vs;
		vs.PushBack("11111");
		vs.PushBack("22222");    //现在这个样子，程序会崩溃；如果是两个程序还可以运行，
		                        //但是4个的话，程序直接就崩溃了，因为增容哪里出现了错误；
		vs.PushBack("33333");   
		vs.PushBack("44444");

		vs[3] = "55555";    //这里充当改的角色；

		for (auto s : vs)
		{
			cout << s << " ";
		}
		cout << endl;

		auto pos = find(vs.begin(), vs.end(), "33333");
		vs.Erase(pos);

		for (const auto& s : vs)
		{
			cout << s << " ";
		}
		cout << endl;

	/*	vs.PopBank();   //这两给是不能同时存在的，当上面的释放一个后，后面是不能在全部释放的；系统访问越界；
		vs.PopBank();
		vs.PopBank();
		vs.PopBank();

		for (auto s : vs)
		{
			cout << s << " ";
		}
		cout << endl;*/


	}

}


int main()
{
	//dpf::TestVector();
	dpf::TestVector1();
	return 0;
}


//typedef const T* constiterator;
//
//iterator Begin(){ return _start };
//iterator End(){ return _finish };
//
//
//constiterator CBegin() const{ return _start };
//constiterator CEnd() const { return _finish };




//class Cpreson
//{
//public:
//	Cpreson(string name = "ooo", string id = "000" , string sex = "ooo", int age = 0)
//		:_name(name)
//		, _id(id)
//		, _sex(sex)
//		, _age(age)
//	{
//		cout << _name << " " << _id << " " << _sex << " " << _age << endl;
//	}
//private:
//	string _name;
//	string _id;
//	string _sex;
//	int _age;
//};
//int main()
//{
//	Cpreson c("wangwu", "123456", "nan", 15);
//return 0;
//}


