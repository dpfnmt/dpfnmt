//#include<iostream>
//using namespace std;
//
//int main()
//{
//	try
//	{
//		char* p = new char[0x7fffffff];
//		cout << (void*)p << endl;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;


//int main()
//{
//	try
//	{
//		//throw 10;
//		char* p = new char[0x7fffffff];
//		cout << (void*)p << endl;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (int i)
//	{
//		cout << i << endl;
//	}
//	return 0;
//}

//void func1()
//{
//	//throw 10;//����func1�ˣ�Ȼ��ֱ������ˡ�
//
//	//throw 10.12909;//���������쳣
//}
//void func2()
//{
//	
//	try
//	{
//		string str("error");
//	    throw str;
//	}
//	catch (const string& str)
//	{
//		cout << str <<__LINE__<< endl;
//	}
//}
//int main()
//{
//	try
//	{
//		func1();
//		func2();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (int i)//���������쳣
//	{
//		cout << i << endl;
//	}
//	catch (const string& str)//����string�쳣
//	{
//		cout << str << __LINE__<< endl;
//	}
//	catch(...) //���������쳣��֪�������쳣�����ǲ�֪������ʲô�쳣��
//	{
//		cout << "δ֪�쳣" << endl;
//	}
//	cout << "end" << endl;
//	return 0;
//}
//
////�����³�������ʾ
//
//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//void Func()
//{
//	//����������������ʱ��
//	int* p = new int[10];
//
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//      
//	delete[] p; //���ﵱ��ĸΪż����ʱ����ô�Ͳ��ܱ���Ч���ͷ��ˣ�������������Ҫ�Լ��ػ��쳣��
//	cout << p << endl;
//}
//void Func()
//{
//	//����������������ʱ��
//	int* p = new int[10];   //�쳣��ȫ����
//	try{
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	//��һ�ֽ��
//	//catch (const char* errmsg)
//	//{
//	//	delete[] p; //���ﵱ��ĸΪż����ʱ����ô�Ͳ��ܱ���Ч���ͷ��ˣ�������������Ҫ�Լ��ػ��쳣��
//	//	cout << p << endl;
//	//	throw errmsg;
//	//}
//	//�ڶ��ֽ��������֪��ʲô�쳣��ʱ��
//	catch (...)
//	{
//		delete[] p;
//		cout << p << endl;
//		throw;
//	}
//	delete[] p;  //���ֻ��������Ļ���ֻ�ͷţ�����û���׳��쳣����������ܴ󣬲��ܸ������洦����ˣ�
//	cout << p << endl;
//}
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (...)
//	{
//		cout << "unkown exception" << endl;
//	}
//	return 0;
//}

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class WChatException
{
public:
	WChatException(int errid , const string& errmsg)
		:_errid(errid)
		, _errmsg(errmsg)
	{}

	virtual ~WChatException()
	{}
	//virtual string what() = 0;
	virtual void log() const = 0;  //�����constû��д

protected:
	int _errid;
	string _errmsg;
	//string _file;
	//string _line;
};
class WChatPayException : public WChatException
{
public:
	WChatPayException(int errid, const string& errmsg , const char* file = "payerrorlog.log")
		:WChatException(errid, errmsg)
		, _file(file)
	{}

	virtual ~WChatPayException()
	{}

	/*virtual string what()
	{}*/

	virtual void log() const
	{
		ofstream ofs(_file);
		ofs << _errmsg << endl;
		ofs << _errid << endl;
	}
private:
	const char* _file;
};
class WChatFrindsException : public WChatException
{
public:
	WChatFrindsException(int errid, const string& errmsg, const char* file = "frindseerrorlog.log")
		:WChatException(errid, errmsg)
		, _file(file)
	{}

	virtual ~WChatFrindsException()
	{}

	/*virtual string what()
	{}*/

	virtual void log() const
	{
		ofstream ofs(_file);
		ofs << _errmsg << endl;
		ofs << _errid << endl;
	}
private:
	const char* _file;
};

void func()
{
	for (size_t i = 0; i < 10; i++)
	{
		if (rand() % 2 == 0)
		{
			WChatPayException e(1, "����");
			throw e;
		}

		if (rand() % 3 == 0)
		{
			WChatFrindsException e(1, "�����쳣");
			throw e;
		}
	}
}

int main()
{
	try
	{
		func();
	}
	catch (const WChatException& e)
	{
		e.log();
	}
	return 0;
}
