#include<iostream>
using namespace  std;


// int main()
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