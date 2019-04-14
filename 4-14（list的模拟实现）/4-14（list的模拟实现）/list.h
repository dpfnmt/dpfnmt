#include<iostream>
#include<list>

using namespace std;


template<class T>
struct _ListNode
{
	T _data;
	_ListNode<T>* _prev;
	_ListNode<T>* _next;
	_ListNode<T>(const T& x = T())
		: _data(x)
		, _prev(nullptr)
		, _next(nullptr)
	{}
};

template<class T>
struct _ListIterator
{
	typedef _ListIterator Node;
	Node* _node;

	_ListIterator(Node* node)
		:_node(node)
	{}
};


template<class T>
class List
{
	typedef _ListNode<T>  Node;
public:
	typedef _ListNode<T>  iterator;
	iterator begin()
	{
		return iterator(_head->_next);
	}
	iterator end()
	{
		return iterator(_head);
	}
	List()
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
	}
	List<T>(const List<T>& l)
	{}
	List<T>& operator=(const List<T>& l);
	~List()
	{
		Clear();
		delete _head;
		_head = nullptr;
	}
	void  Clear()
	{
		Node* cur = _head->_next;
		while (cur != _head)
		{
			Node* next = cur->_next;
			//cur = next;
			delete cur;
			cur = next;
		}
		_head->_next = _head;
		_head->_prev = _head;
	}

	void PushBack(const T& x)
	{
		Node* newnode = new Node(x);
		Node* tail = _head->_prev;

		tail->_next = newnode;
		newnode->_prev = tail;
		newnode->_next = _head;
		_head->_prev = newnode;
	}
	void PopBack();
	void PushFront(const T& x);
	void PopFront();

	//void Insert(iterator pos, const T& x);
private:
	Node* _head;
};
