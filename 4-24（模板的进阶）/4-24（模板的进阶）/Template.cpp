#include<iostream>
using  namespace std;

//class Preson
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "��ȫƱ" << endl;
//	}
//};
//class Student :public Preson
//{
//	virtual void BuyTicket()
//	{
//		cout << "���Ʊ" << endl;
//	}
//};
//
//void Func(Preson& people)
//{
//	people.BuyTicket();
//}
//int main()
//{
//	Preson p;
//	//Func(p);
//	p.BuyTicket();
//
//	Student s;
//	Func(s);
//	//ʹ�������������ִ�����Ϊ��������ʹ��virtual�ؼ����ˣ�
//	//s.BuyTicket(); 
//
//	return 0;
//}

//class A{};
//class B : public A {};
//class Person {
//public:
//	virtual A* f()
//	{
//		return new A;
//	}
//};
//class Student : public Person {
//public:
//	virtual B* f() 
//	{ 
//		return new B;
//
//	}
//};
//
//void func(Person& ps)
//{
//	ps.f();
//}
//int main()
//{
//	Person p;
//	func(p);
//
//	Student s;
//	func(s);
//}

//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//	return 0;
//}

//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-����" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-�ٿ�" << endl;
//	}
//};

//class Car{
//public:
//	virtual void Drive()
//	{}
//};
//// 2.override �����������麯��ǿ�������д
//class Benz :public Car {
//public:
//	virtual void Drive() override
//	{
//		cout << "Benz-����" << endl;
//	}
//};
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-����" << endl; }
//};
//void Test()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//	//Car* pBMW = new BMW;
//	//pBMW->Drive();
//}

class Base
{
public:
	virtual void Func1()
	{
		cout << "bFunc1()" << endl;
	}
	virtual void Func2()
	{
		cout << "bFunc2()" << endl;
	}
	void Func3()
	{
		cout << "bFunc3()" << endl;
	}
private:
	int _b = 1;
};
class Derive:public Base
{
public:
	virtual void Func1()
	{
		cout << "dFunc1()"<< endl;
	}
private:
	int _d = 2;
};
int main()
{
	Base b;
	Derive d;
	return 0;
}