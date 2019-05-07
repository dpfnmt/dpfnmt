#include<iostream>
#include <map>
#include <string>
using namespace std;

void TestMultimap1()
{
	multimap<string, string> m;
	m.insert(make_pair("����", "������"));
	m.insert(make_pair("�ֳ�", "����ͷ"));
	m.insert(make_pair("³��", "������"));
	m.insert(make_pair("����", "��ţ"));
	cout << m.size() << endl;
	for (auto& e : m)
		cout << "<" << e.first << "," << e.second << ">" << endl;
	// keyΪ���ӵ�Ԫ���ж��ٸ�
	cout << m.count("����") << endl;
	cout << m.count("�ֳ�") << endl;
	//return 0;
}
void TestMultimap2()
{
	multimap<int, int> m;
	for (int i = 0; i < 10; ++i)
		m.insert(pair<int, int>(i, i));
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	cout << endl;
	// ����m�д��ڵ���5�ĵ�һ��Ԫ��
	auto it = m.lower_bound(5);
	cout << it->first << "--->" << it->second << endl;
	// ����m�д���5��Ԫ��
	it = m.upper_bound(5);
	cout << it->first << "--->" << it->second << endl;


}
//
//int main()
//{
//	//TestMultimap1();
//	TestMultimap2();
//	return 0;
//}

int main()
{
	std::multimap<char, int> mymm;

	mymm.insert(std::pair<char, int>('a', 10));
	mymm.insert(std::pair<char, int>('b', 20));
	mymm.insert(std::pair<char, int>('a', 30));
	mymm.insert(std::pair<char, int>('b', 40));
	mymm.insert(std::pair<char, int>('c', 50));
	mymm.insert(std::pair<char, int>('c', 60));
	mymm.insert(std::pair<char, int>('d', 60));

	std::cout << "mymm contains:\n";
	for (char ch = 'a'; ch <= 'd'; ch++)
	{
		std::pair <std::multimap<char, int>::iterator, std::multimap<char, int>::iterator> ret;
		ret = mymm.equal_range(ch);
		std::cout << ch << " =>";
		for (std::multimap<char, int>::iterator it = ret.first; it != ret.second; ++it)
			std::cout << ' ' << it->second;
		std::cout << '\n';
	}

	return 0;
}