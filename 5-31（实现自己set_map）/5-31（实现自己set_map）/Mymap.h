#pragma once
#include"RBTree.h"

template<class K,class T>
class MyMap
{
private:
	RBTree< K, pair<K, T> t;
};