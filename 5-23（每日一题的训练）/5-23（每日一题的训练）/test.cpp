//#pragma once
//#include<iostream>
//
//using namespace std;
//#include<map>
//#include<set>
//#include<windows.h>
//#include <stdlib.h>
//#include <assert.h>
//
//template<class K, class V>
//struct AVLTreeNode
//{
//	AVLTreeNode<K, V>* _left;
//	AVLTreeNode<K, V>* _right;
//	AVLTreeNode<K, V>* _parent;
//	int _bf;
//	pair<K, V> _kv;
//
//	AVLTreeNode(const pair<K, V>& kv)
//		:_left(nullptr)
//		, _right(nullptr)
//		, _parent(nullptr)
//		, _bf(0)
//		, _kv(kv)
//	{}
//};
//
//template<class K, class V>
//class AVLTree
//{
//	typedef AVLTreeNode<K, V> Node;
//public:
//	AVLTree()
//		:_root(nullptr)
//	{}
//
//	~AVLTree()
//	{
//		DestoryTree(_root);
//		_root = nullptr;
//	}
//
//	void DestoryTree(Node* root)//销毁树
//	{
//		if (root == nullptr)
//			return;
//		DestoryTree(root->_left);
//		DestoryTree(root->_right);
//		delete root;
//	}
//
//	bool Insert(const pair<K, V>& kv)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(kv);
//			return true;
//		}
//		Node* parent = nullptr;//保存需要插入节点的上一个节点
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_kv.first > kv.first)//如果插入的值比当前节点的值小，就走左子树
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else if (cur->_kv.first < kv.first)//如果插入的值比当前节点的值大，就走右子树
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else
//			{
//				return false;//说明节点已经存在
//			}
//		}
//		cur = new Node(kv);
//		if (parent->_kv.first < kv.first)//判断当前cur节点应该链在上一个节点的哪边
//		{
//			parent->_right = cur;
//			cur->_parent = parent;//这里是三叉链，一定要链起来
//		}
//		else
//		{
//			parent->_left = cur;
//			cur->_parent = parent;
//		}
//
//		while (parent)//当parent为nullptr时不再更新
//		{
//			if (cur == parent->_right)//跟新平衡因子
//				parent->_bf++;
//			else
//				parent->_bf--;
//
//			if (parent->_bf == 0)//满足规则，结束
//			{
//				break;
//			}
//			else if (abs(parent->_bf) == 1)//高度变了，继续跟新
//			{
//				cur = parent;
//				parent = parent->_parent;
//			}
//			else if (abs(parent->_bf) == 2)//不满足规则，需要旋转
//			{
//				if (parent->_bf == 2)
//				{
//					if (cur->_bf == 1)//树呈 \ 状
//					{
//						RotateL(parent);
//					}
//					else if (cur->_bf == -1)//树呈 > 状
//					{
//						RotateRL(parent);
//					}
//				}
//				else if (parent->_bf == -2)
//				{
//					if (cur->_bf == -1)//树呈 / 状
//					{
//						RotateR(parent);
//					}
//					else if (cur->_bf == 1)//树呈 < 状
//					{
//						RotateLR(parent);
//					}
//				}
//				//旋转完成,不会影响上一层
//				break;
//			}
//			else
//			{
//				//出现这种情况说明平衡因子错误
//				assert(false);
//			}
//		}
//		return true;
//	}
//}
//}

#include<iostream>
#include<string>

using namespace std;

//int main()
//{
//	vector<int> v;
//	string s;
//	cin >> s;
//	int i = 0;
//	v.insert = s;
//	int j[] = { 0 };
//	while (v[s])
//	{
//		for (i = 0; i <= v.size(); i++)
//		{
//			if (v[i] >= 'a' && v[i] <= 'z' || v[i] >= '0' && v[i] <= '9')
//			{
//				if (v[i] >= 'a' && v[i] <= 'z')
//				{
//					i++;
//					cout << j[v[i]];
//				}
//				else if (v[i] >= '0' && v[i] <= '9')
//				{
//					i++;
//					cout << j[v[i]];
//				}
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//	return j[v[i]];
//}

//int main()
//{
//	string s;
//	cin >> s;
//	string str;
//	int lenght = 0;
//	int pos = 0;
//	for (int i = 0, j = 0; j < s.size();)
//	{
//		if (s[i] < '0' && s[j] > '9')
//		{
//			++j;
//			i = j;
//		}
//		else
//		{
//			 ++j;
//			if ((j - i) >lenght)
//			{
//				pos = i;
//				lenght = j - i;
//			}
//		}
//	}
//	str = s.substr(pos, lenght);
//	cout << str;
//
//	return 0;
//}
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		int i;
//		int max = 0;
//		string ss;
//		string out;
//		for (i = 0; i < str.size(); i++)
//		{
//			if (str[i] >= '0' &&str[i] <= '9')
//			{
//				ss += str[i];
//				while (str[i + 1] >= '0' &&str[i + 1] <= '9')
//				{
//					i++;
//					ss += str[i];
//				}
//				if (ss.size() > max)
//				{
//					max = ss.size();
//					out = ss;
//				}
//				else if (ss.size() == max)
//					out += ss;
//			}
//			else if (str[i] >= 'a' &&str[i] <= 'z')
//			{
//				ss += str[i];
//				while (str[i + 1] >= 'a' &&str[i + 1] <= 'z')
//				{
//					i++;
//					ss += str[i];
//				}
//				if (ss.size() > max)
//				{
//					max = ss.size();
//					out = ss;
//				}
//				else if (ss.size() == max)
//					out += ss;
//			}
//		}
//		ss.clear();
//	}
//		cout << out << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <string>
//#include <sstream>
//using namespace std; 
//int main(){    
//	string str;    
//	while(cin >> str){        
//	for(auto &c : str){            
//		if(!isdigit(c))                
//			c = ' ';        
//	}         
//	stringstream ss(str);        
//	unsigned int max_sz = 0;        
//	string s, o;        
//	while(ss >> s){            
//		if(max_sz < s.size()){                
//			max_sz = s.size();                
//			o = s;            }
//		else if(max_sz == s.size())                
//			o += s;        
//	}         
//	if(max_sz != 0)            
//		cout << o <<  endl;    
//}    
//return 0;
//}

#include<iostream>
using namespace std;int main(){    
	int a[1000]={0};//数组置0，然后输入n，则对应位置加1，最后遍历数组    
	int n,num=0;  //找到大于等于一半次数的那个    
	while(cin>>n){       
		a[n]++;        
		num++;    
	}    
	for(int i=0;i<num;i++){        
		if(a[i]>=num/2)            
			cout<<i<<endl;    
	}   
return 0;
}