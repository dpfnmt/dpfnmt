#include<iostream>
using namespace std;

//template<class K, class V>
//struct AVLTreeNode
//{
//	AVLTreeNode<K, V>* _left;
//	AVLTreeNode<K, V>* _right;
//	AVLTreeNode<K, V>* _parent;
//
//	std::pair<K, V> _kv;
//	int _bf; // balance factor
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
//	bool Insert(const std::pair<K, V>& kv)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(kv);
//			return true;
//		}
//
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_kv.first > kv.first)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else if (cur->_kv.first < kv.first)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else
//			{
//				return false;
//			}
//		}
//
//		cur = new Node(kv);
//		if (parent->_kv.first < kv.first)
//		{
//			parent->_right = cur;
//			cur->_parent = parent;
//		}
//		else
//		{
//			parent->_left = cur;
//			cur->_parent = parent;
//		}
//
//		// 更新平衡因子
//		while (parent)
//		{
//			// 1.cur是parent的左边--bf cur是parent的右边++bf
//			if (cur == parent->_left)
//				parent->_bf--;
//			else
//				parent->_bf++;
//
//			// 1.parent == 0 高度不变，更新结束
//			// 2.parent == 1、-1.高度变了，继续更新
//			// 2.parent == 2、-2.不平衡，旋转变成平衡树，降低高度
//			if (parent->_bf == 0)
//			{
//				break;
//			}
//			else if (abs(parent->_bf) == 1)
//			{
//				cur = parent;
//				parent = parent->_parent;
//			}
//			else if (abs(parent->_bf) == 2)
//			{
//				// 旋转
//			}
//			else
//			{
//				assert(false);
//			}
//		}
//
//		return true;
//	}
//
//	void RotateL(Node* parent)
//	{
//		Node* subR = parent->_right;
//		Node* subRL = subR->_left;
//
//		parent->_right = subRL;
//		if (subRL)
//			subRL->_parent = parent;
//
//		subR->_left = parent;
//		Node* ppnode = parent->_parent;
//		parent->_parent = subR;
//
//		if (_root == parent)
//		{
//			_root = subR;
//			_root->_parent = nullptr;
//		}
//		else
//		{
//			if (ppnode->_left == parent)
//				ppnode->_left = subR;
//			else
//				ppnode->_right = subR;
//
//			subR->_parent = ppnode;
//		}
//
//		parent->_bf = subR->_bf = 0;
//	}
//
//	void RotateR(Node* parent)
//	{
//		Node* subL = parent->_left;
//		Node* subLR = subL->_right;
//
//		parent->_left = subLR;
//		if (subLR)
//			subLR->_parent = parent;
//
//		subL->_right = parent;
//		Node* ppnode = parent->_parent;
//		parent->_parent = subL;
//		if (parent == _root)
//		{
//			_root = subL;
//		}
//		else
//		{
//			if (ppnode->_left == parent)
//				ppnode->_left = subL;
//			else
//				ppnode->_right = subL;
//		}
//
//		subL->_parent = ppnode;
//		subL->_bf = parent->_bf = 0;
//	}
//
//private:
//	Node* _root;
//};
#include<iostream>
#include<windows.h>
#include<assert.h>
using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;
	pair<K, V> _kv;

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _kv(kv)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(nullptr)
	{}

	~AVLTree()
	{
		DestoryTree(_root);
		_root = nullptr;
	}

	void DestoryTree(Node* root)//销毁树
	{
		if (root == nullptr)
			return;
		DestoryTree(root->_left);
		DestoryTree(root->_right);
		delete root;
	}

	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* parent = nullptr;//保存需要插入节点的上一个节点
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)//如果插入的值比当前节点的值小，就走左子树
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)//如果插入的值比当前节点的值大，就走右子树
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;//说明节点已经存在
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)//判断当前cur节点应该链在上一个节点的哪边
		{
			parent->_right = cur;
			cur->_parent = parent;//这里是三叉链，一定要链起来
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		while (parent)//当parent为nullptr时不再更新
		{
			if (cur == parent->_right)//跟新平衡因子
				parent->_bf++;
			else
				parent->_bf--;

			if (parent->_bf == 0)//满足规则，结束
			{
				break;
			}
			else if (abs(parent->_bf) == 1)//高度变了，继续跟新
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)//不满足规则，需要旋转
			{
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)//树呈 \ 状
					{
						RotateL(parent);
					}
					else if (cur->_bf == -1)//树呈 > 状
					{
						RotateRL(parent);
					}
				}
				else if (parent->_bf == -2)
				{
					if (cur->_bf == -1)//树呈 / 状
					{
						RotateR(parent);
					}
					else if (cur->_bf == 1)//树呈 < 状
					{
						RotateLR(parent);
					}
				}
				//旋转完成,不会影响上一层
				break;
			}
			else
			{
				//出现这种情况说明平衡因子错误
				assert(false);
			}
		}
		return true;
	}

	void RotateR(Node* parent)//右单旋
	{
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;
		parent->_left = SubLR;
		if (SubLR)
		{
			SubLR->_parent = parent;
		}
		SubL->_right = parent;
		Node* pNode = parent->_parent;
		parent->_parent = SubL;
		if (parent == _root)
		{
			_root = SubL;
		}
		else
		{
			if (pNode->_left == parent)
			{
				pNode->_left = SubL;
			}
			else
			{
				pNode->_right = SubL;
			}
		}
		SubL->_parent = pNode;
		parent->_bf = SubL->_bf = 0;
	}

	void RotateL(Node* parent)//左单旋
	{
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;
		parent->_right = SubRL;
		if (SubRL)
		{
			SubRL->_parent = parent;
		}
		SubR->_left = parent;
		Node* pNode = parent->_parent;//记录当前parent的父亲节点，以便让SubR指向当前parent的父亲节点
		parent->_parent = SubR;
		if (_root == parent)
		{
			_root = SubR;
		}
		else
		{
			if (pNode->_left == parent)
			{
				pNode->_left = SubR;
			}
			else
			{
				pNode->_right = SubR;
			}
		}
		SubR->_parent = pNode;
		parent->_bf = SubR->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;
		int bf = SubLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);
		if (bf == 1)
		{
			SubL->_bf = -1;
			parent->_bf = 0;
		}
		else if (bf == -1)
		{
			SubL->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 0)
		{
			parent->_bf = SubL->_bf = 0;
		}
		SubLR->_bf = 0;
	}

	void RotateRL(Node* parent)
	{
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;
		int bf = SubRL->_bf;//记录右左双旋之前SubRL的平衡因子

		RotateR(parent->_right);
		RotateL(parent);
		if (bf == 1)
		{
			SubR->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1)
		{
			SubR->_bf = 1;
			parent->_bf = 0;
		}
		else if (bf == 0)//说明我自己就是刚刚插入的节点
		{
			parent->_bf = SubR->_bf = 0;
		}
		SubRL->_bf = 0;
	}

	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}

	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;
		_Inorder(root->_left);
		cout << root->_kv.first << " ";
		_Inorder(root->_right);
	}

	bool IsBlanace()//判断树是否为平衡树
	{
		return _IsBlanace(_root);
	}

	bool _IsBlanace(Node* root)
	{
		if (root == nullptr)
			return true;
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);

		return abs(leftHeight - rightHeight) < 2 && _IsBlanace(root->_left) && _IsBlanace(root->_right);
	}

	int _Height(Node* root)//求树的高度
	{
		if (root == nullptr)
			return 0;

		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		return rightHeight > leftHeight ? rightHeight + 1 : leftHeight + 1;
	}
private:
	Node* _root;
};


int main()
{
	AVLTree a;

}