#pragma once
#include"RBTree.h"

template<class K>
class MySet
{
public:
	bool Insert(const K& key)
	{
		return t.Insert(key);
	}
private:
	RBTree<K, K> t;
};

void TestSet()
{
	MySet<int> s;
	s.Insert(1);
	s.Insert(2);
	s.Insert(4);
	s.Insert(3);
	s.Insert(6);
	s.Insert(5);
}