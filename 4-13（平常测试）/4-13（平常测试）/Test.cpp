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
		cout << "ѧ������:" << _name << endl;
		cout << "ѧ���ձ�:" << _sex << endl;
		cout << "ѧ������:" << _age << endl;
		cout << "ѧ��ѧ��:" << _number << endl;
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
	Student s("��", "��", 45,"13080923745");
	cout << "2" << endl;
	s.Show();
	cout << "3";
	return 0;
}