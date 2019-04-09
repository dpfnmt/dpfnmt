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
			if (n > Capacity())  //��������д()��
			{
				size_t size = Size();
				T* tmp = new T[n];

				if (size > 0)
				{
					//memcpy(tmp, _start, sizeof(T)*size); //T����֪��ʲô���ͣ����ﲻ֪��ʲô���͵�
					for (size_t i = 0; i < size; i++)   //�����൱��string�ĸ�ֵ
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
			Erase(_finish - 1); // ���ﲻ����--(����finish)��Ҫ�� (finish-1) ,�����ǲ�һ����
		}
		void Insert(iterator& pos, const T& x)  //������ֵ�����ʱЧ���� ��Ҫ��&
		{
			size_t n = pos - _start;   //�ͷſռ䣬posλ���Ҳ���������ӵĻ���̫���ˣ�Ӧ���ȱ���ǰ����ڼӡ�
			if (_finish == _endofStorage)
			{
				size_t newcapacity = Capacity() == 0 ? 2 : Capacity() * 2;   //��������������д()�ˣ�
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
		iterator  _start;  //ָ�����ݿ��ͷ
		iterator  _finish; //ָ����Ч���ݵ�β
		iterator  _endofStorage;    //ָ�򴢴�������β
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
		auto it = v.begin();   //c++11 ���� 
		                       //���������ȱ�ݣ���֪��ǰ���������ʲô������ǰ���Ϊconst����Ҳ��֪��
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (const auto& e : v)  //�����vΪint�ͣ������ñȽϺ�һ��
		{
			cout << e << " ";
		}
		cout << endl; 

	}

	void TestVector1()
	{
		Vector<string> vs;
		vs.PushBack("11111");
		vs.PushBack("22222");    //����������ӣ�����������������������򻹿������У�
		                        //����4���Ļ�������ֱ�Ӿͱ����ˣ���Ϊ������������˴���
		vs.PushBack("33333");   
		vs.PushBack("44444");

		vs[3] = "55555";    //����䵱�ĵĽ�ɫ��

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

	/*	vs.PopBank();   //�������ǲ���ͬʱ���ڵģ���������ͷ�һ���󣬺����ǲ�����ȫ���ͷŵģ�ϵͳ����Խ�磻
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


