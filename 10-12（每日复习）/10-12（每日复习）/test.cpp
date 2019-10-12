//int main()
//{
//	String s1("hello");
//	String s2("hello");
//
//	//s1 += s2;
//	//String ret = s1 + s2;
//	String ret;
//	ret = s1 + s2;
//
//	vector<string> v;
//	string str("world");
//	v.push_back(str);
//	//v.push_back(move(str));
//	v.push_back("hello");
//
//	v.emplace_back("hello");
//	v.emplace_back(str);
//	v.emplace_back(move(str));
//
//	vector<Date> vd;
//	Date d1(2019, 6, 25);
//	vd.push_back(d1); // ��ֵ
//	vd.push_back(Date(2019, 6, 26)); // ��ֵ
//	//vd.push_back(2019, 6, 26);
//
//
//	vd.emplace_back(Date(2019, 6, 26));
//	vd.emplace_back(d1);
//	//vd.emplace_back(2019, 6, 26);
//
//
//	return 0;
//}

void Fun(int &x){ cout << "lvalue ref" << endl; }
void Fun(int &&x){ cout << "rvalue ref" << endl; }
//void Fun(const int &x){ cout << "const lvalue ref" << endl; }
//void Fun(const int &&x){ cout << "const rvalue ref" << endl; }

template<typename T>
void PerfectForward(T &&t){ Fun(std::forward<T>(t)); }

//int main()
//{
//	PerfectForward(10); // rvalue re
//	int a;
//	PerfectForward(a);			   // lvalue ref
//	PerfectForward(std::move(a)); // rvalue ref
//
//	//const int b = 8;
//	//PerfectForward(b); // const lvalue ref
//	//PerfectForward(std::move(b)); // const rvalue ref
//
//	return 0;
//}
typedef bool(*GTF)(int, int);
bool greater_func1(int l, int r)
{
	return l > r;
}

struct greater_func2
{
	bool operator()(int l, int r)
	{
		return l > r;
	}
};

//int main()
//{
//	// ����ָ�롢�º�����lamber�÷�����һ���ġ�
//	// ����ָ�� ���Ͷ��������
//	// �º���  ���������  �ȶ���ã�����
//	// lamber �ֶ�������
//	//GTF f1 = greater_func1;
//	bool(*f1)(int, int) = greater_func1;
//	cout << f1(1, 2) << endl;
//
//	greater_func2 f2;
//	cout << f2(1, 2) << endl;
//
//	//       ��׽�б� �����б� ����ֵ ������
//	auto f3 = [](int l, int r)->bool{return l > r; };
//	cout << f3(1, 2) << endl;
//
//	int a[] = { 1, 4, 5, 2, 6, 9, 8, 7 };
//	sort(a, a + sizeof(a) / sizeof(int), f1);
//	sort(a, a + sizeof(a) / sizeof(int), f2);
//	sort(a, a + sizeof(a) / sizeof(int), f3);
//
//
//	return 0;
//}

struct Goods
{
	string _name;
	double _price;
	double _appraise;
};

int main()
{
	Goods gds[] = { { "ƻ��", 2.1, 10 }, { "�ཻ", 3, 8 }, { "����", 2.2, 7 }, { "����", 1.5, 10 } };

	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2)->bool
	{return g1._price > g2._price; });

	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2)->bool
	{return g1._appraise > g2._appraise; });

	return 0;
}