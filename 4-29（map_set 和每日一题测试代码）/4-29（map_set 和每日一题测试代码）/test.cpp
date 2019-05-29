#include<iostream>
using namespace std;
#include<map>
#include<vector>
#include<string>

void test_map1()
{
	std::map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(5, 5));
	m.insert(make_pair(4, 4));

	std::map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		//cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;
}
//ͳ�ƴ���
void test_map2() 
{
	string s[] = { "ƻ��", "ƻ��", "ƻ��", "ƻ��", "����", "ƻ��", "ƻ��", "�㽶", "ƻ��", "�㽶", "ƻ��" };
	map<string, int> countmap;
	for (const auto& e : s)
	{
		map<string, int>::iterator it = countmap.find(e);
		//auto it = countmap.find(e);
		if (it != countmap.end())
		{
			it->second++;
		}
		else
		{
			countmap.insert(make_pair(e, 1));
		}
	}
	map<string, int>::iterator cit = countmap.begin();
	while (cit != countmap.end())
	{
		//cout << (*it).first << ":" << (*it).second << endl;
		cout << cit->first << ":" << cit->second << endl;
		++cit;
	}
}
void test_map3() //ͳ�ƴ���
{
	string s[] = { "ƻ��", "ƻ��", "ƻ��", "ƻ��", "����", "ƻ��", "ƻ��", "�㽶", "ƻ��", "�㽶", "ƻ��" };
	map<string, int> countmap;
	for (const auto& e : s) //������find();
	{
		pair<map<string, int>::iterator, bool> ret = countmap.insert(make_pair(e, 1));
		//auto ret = countmap.insert(make_pair(e, 1));
		//autoȱ�ݣ������׶�ȡ����֪������ʲô����
		if (ret.second == false)
		{
			ret.first->second++;
		}
	}
	map<string, int>::iterator cit = countmap.begin();
	while (cit != countmap.end())
	{
		//cout << (*it).first << ":" << (*it).second << endl;
		cout << cit->first << ":" << cit->second << endl;
		++cit;
	}
}
void test_map4()
{
	string strs[] = { "ƻ��", "ƻ��", "����", "ƻ��", "����", "��ݮ", "��ݮ", "�㽶", "ƻ��", "ƻ��", "�㽶", "�㽶", "ƻ��", "ƻ��" };
	map<string, int> countmap;
	for (const auto& e : strs)
	{
		countmap[e]++;
	}

	for (const auto& e : countmap)
	{
		cout << e.first << ":" << e.second << endl;
	}

}
void test_map5()
{
	map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(5, 5));
	m.insert(make_pair(4, 4));
	m[1] = 1;
	//��ĳһ��λ�ò���һ��ֵ
	m.insert(m.find(2), make_pair(6, 6));
	cout << m.size() << endl;
	//������������һ�飬��ӡ
	for (auto& e : m )
	{
		cout << e.first << "--->" << e.second << endl;
	}

	// map�еļ�ֵ��keyһ����Ψһ�ģ����key���ڽ�����ʧ��
	auto ret = m.insert(make_pair(7, 7));
	if (ret.second)
		cout << "<7, 7>����map��, �Ѿ�����" << endl;
	else
		cout << "��ֵΪpeach��Ԫ���Ѿ����ڣ�" << ret.first->first << "--->"
		<< ret.first->second << " ����ʧ��" << endl;
	//������Ĵ�ӡ����
	for (auto& e : m)
	{
		cout << e.first << "--->" << e.second << endl;
	}
	cout << "������������������������"<<endl;
	//ɾ��keyΪ4��ֵ
	m.erase(4);
	for (auto& e : m)
	{
		cout << e.first << "--->" << e.second << endl;
	}
	cout << "������������������������" << endl;

	if (4 == m.count(4))
		cout << "4����" << endl;
	else
		cout << "4������" << endl;
}
int main()
{
	//test_map1();
	//test_map2();
	//test_map3();
	//test_map4();
	test_map5();

	return 0;
}