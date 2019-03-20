//#include<iostream>
//#include<string>
//
//using namespace std;
//
//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << "peter"<< endl;
//	}
//protected:
//	string _name; // 姓名
//private:
//	int _age; // 年龄
//};
//
////class Student : protected Person    //夫类公共，子类保护，子类就不能直接访问父类就访问不了；父类可以访问自己
////class Student : public Person    //公共和公共就可以直接 子在夫中直接调用；
//class Student : private Person    //夫类公共，子类私有，在调用的时候也是不能直接被访问的。
//{
//protected:
//	int _stunum; // 学号
//};
//
//int main()
//{
//	Person p;
//	p.Print();
//	Student s;
//	s.Print();
//	return 0;
//}

//class Person
//{
//protected:
//	string _name; // 姓名
//	string _sex; // 性别
//	int _age; // 年龄
//};
//
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//
//int main()
//{
//	Student s;   // 1.子类对象可以赋值给父类对象/指针/引用
//	Person p = s;
//	Person* pp = &p; // 在这里需要将取地址符加上，要不然无法有 person 转化成 person*；
//
//	//s = p; //2.无法赋值由基类直接到派生类；
//
//	pp = &s;
//	Student* s1 = (Student*)pp;
//	s1->_No = 10;
//
//	pp = &p;
//	Student* s2 = (Student*)pp;
//	s2->_No = 10;
//	return 0;
//}


//#include<iostream>
//#include<string>
//
//using namespace std;
//
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << _num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//
//int main()
//{
//	Student s1;
//	s1.Print();
//	return 0;
//}

#include<iostream>
#include<string>

using namespace std;

class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};
class B : public A
{
public:
	void fun(int i)
	{
		A::fun();
		cout << "func(int i)->" << i << endl;
	}
};
int main()
{
	A a;
	a.fun();
	B b;
	b.fun(10);
}