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
//	void DestoryTree(Node* root)//������
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
//		Node* parent = nullptr;//������Ҫ����ڵ����һ���ڵ�
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_kv.first > kv.first)//��������ֵ�ȵ�ǰ�ڵ��ֵС������������
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else if (cur->_kv.first < kv.first)//��������ֵ�ȵ�ǰ�ڵ��ֵ�󣬾���������
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else
//			{
//				return false;//˵���ڵ��Ѿ�����
//			}
//		}
//		cur = new Node(kv);
//		if (parent->_kv.first < kv.first)//�жϵ�ǰcur�ڵ�Ӧ��������һ���ڵ���ı�
//		{
//			parent->_right = cur;
//			cur->_parent = parent;//��������������һ��Ҫ������
//		}
//		else
//		{
//			parent->_left = cur;
//			cur->_parent = parent;
//		}
//
//		while (parent)//��parentΪnullptrʱ���ٸ���
//		{
//			if (cur == parent->_right)//����ƽ������
//				parent->_bf++;
//			else
//				parent->_bf--;
//
//			if (parent->_bf == 0)//������򣬽���
//			{
//				break;
//			}
//			else if (abs(parent->_bf) == 1)//�߶ȱ��ˣ���������
//			{
//				cur = parent;
//				parent = parent->_parent;
//			}
//			else if (abs(parent->_bf) == 2)//�����������Ҫ��ת
//			{
//				if (parent->_bf == 2)
//				{
//					if (cur->_bf == 1)//���� \ ״
//					{
//						RotateL(parent);
//					}
//					else if (cur->_bf == -1)//���� > ״
//					{
//						RotateRL(parent);
//					}
//				}
//				else if (parent->_bf == -2)
//				{
//					if (cur->_bf == -1)//���� / ״
//					{
//						RotateR(parent);
//					}
//					else if (cur->_bf == 1)//���� < ״
//					{
//						RotateLR(parent);
//					}
//				}
//				//��ת���,����Ӱ����һ��
//				break;
//			}
//			else
//			{
//				//�����������˵��ƽ�����Ӵ���
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
	int a[1000]={0};//������0��Ȼ������n�����Ӧλ�ü�1������������    
	int n,num=0;  //�ҵ����ڵ���һ��������Ǹ�    
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