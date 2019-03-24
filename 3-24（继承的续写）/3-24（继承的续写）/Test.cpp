//#include<iostream>
//using namespace std;

//class Person final
//{
//public:
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//	~Person()     //�����������������û��������
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // ����
//};
//class Student : public Person
//{
//public:
//	Student(const char* name, int num)
//		: Person(name)
//		, _num(num)
//	{
//		cout << "Student()" << endl;
//	}
//	
//	Student(const Student& s)
//		: Person(s)
//		, _num(s._num)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//	
//	Student& operator = (const Student& s)
//	{
//		cout << "Student& operator= (const Student& s)" << endl;
//		if (this != &s)
//		{
//			Person::operator =(s);
//			_num = s._num;
//		}
//		return *this;
//	}
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//protected:
//	int _num; //ѧ��
//};
//void Test()
//{
//	Student s1("jack",18);
//	Student s2(s1);
//	//Student s3("rose", 17);
//	//s1 = s3;
//}
//
//
//int main()
//{
//	Test();
//	return 0;
//}

//#include<iostream>
//#include<string.h>
//using namespace std;
//
//
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // ����
//};
//
//class Student : public Person
//{
//protected :
//
//	int _stuNum; // ѧ��
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout <<  p._name << endl;
//	cout <<  s._stuNum << endl;
//}
//
//void Test()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

#include<iostream>
#include<string.h>

using namespace std;

class Person 
{
public:
	 Person()
	{
		++_count; 
	}
protected:
	string _name; // ����
public:
	static int _count; // ͳ���˵ĸ�����
};
     int Person::_count = 2;
class Student : public Person 
{
protected:
	static int _stuNum; // ѧ��
};
class Graduate : public Student
{
protected:
	static string _seminarCourse; // �о���Ŀ
};
void TestPerson()
{
	//Person  p0;
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " renshu:" << Person::_count << endl;
	Student::_count = 0;
	cout << " renshu:" << Person::_count << endl;
}
int main()
{
	TestPerson();
	return 0;
}