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
//	string _name; // ����
//private:
//	int _age; // ����
//};
//
////class Student : protected Person    //���๫�������ౣ��������Ͳ���ֱ�ӷ��ʸ���ͷ��ʲ��ˣ�������Է����Լ�
////class Student : public Person    //�����͹����Ϳ���ֱ�� ���ڷ���ֱ�ӵ��ã�
//class Student : private Person    //���๫��������˽�У��ڵ��õ�ʱ��Ҳ�ǲ���ֱ�ӱ����ʵġ�
//{
//protected:
//	int _stunum; // ѧ��
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
//	string _name; // ����
//	string _sex; // �Ա�
//	int _age; // ����
//};
//
//class Student : public Person
//{
//public:
//	int _No; // ѧ��
//};
//
//int main()
//{
//	Student s;   // 1.���������Ը�ֵ���������/ָ��/����
//	Person p = s;
//	Person* pp = &p; // ��������Ҫ��ȡ��ַ�����ϣ�Ҫ��Ȼ�޷��� person ת���� person*��
//
//	//s = p; //2.�޷���ֵ�ɻ���ֱ�ӵ������ࣻ
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
//	string _name = "С����"; // ����
//	int _num = 111; // ���֤��
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << " ���֤��:" << _num << endl;
//		cout << " ѧ��:" << _num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
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