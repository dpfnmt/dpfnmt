#include<iostream>
#include <map>
#include <string>
using namespace std;

void TestMultimap1()
{
	multimap<string, string> m;
	m.insert(make_pair("李逵", "黑旋风"));
	m.insert(make_pair("林冲", "豹子头"));
	m.insert(make_pair("鲁达", "花和尚"));
	m.insert(make_pair("李逵", "铁牛"));
	cout << m.size() << endl;
	for (auto& e : m)
		cout << "<" << e.first << "," << e.second << ">" << endl;
	// key为李逵的元素有多少个
	cout << m.count("李逵") << endl;
	cout << m.count("林冲") << endl;
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
	// 返回m中大于等于5的第一个元素
	auto it = m.lower_bound(5);
	cout << it->first << "--->" << it->second << endl;
	// 返回m中大于5的元素
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