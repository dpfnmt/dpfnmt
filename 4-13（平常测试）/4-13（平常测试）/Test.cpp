#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
	Student(string name = "ooo", string sex = "ooo", int a = 0, string n = 000)
		: _name(name)
		,_sex(sex)
		,_age(a)
		,_number(n)
	{
		cout << _name << "-" << _sex << "-" << _age << "-" << _number << endl;
	}
	void Show()
	{
		cout << "学生姓名:" << _name << endl;
		cout << "学生姓别:" << _sex << endl;
		cout << "学生年龄:" << _age << endl;
		cout << "学生学号:" << _number << endl;
	}

private:
	string _name;
	string _sex;
	int  _age;
	string  _number;
};
int main()
{
	cout << "1" << endl;
	Student s("郭", "男", 45,"13080923745");
	cout << "2" << endl;
	s.Show();
	cout << "3";
	return 0;
}