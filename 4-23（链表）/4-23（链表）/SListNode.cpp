#include"SListNode.h"

void SListDestory(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		SListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
}
SListNode* BuySListNode(SLTDataType x)
{
	SListNode * node = (SListNode*)malloc(sizeof(SListNode));
	assert(node);
	node->_data = x;
	node->_next = NULL;
	return node;
}
//先构建一个链表
void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;

}
//尾插
void SListPushBack(SList* plist, SLTDataType x)
{
	SListNode* tail = plist->_head;
	SListNode*newtail;
	assert(plist);
	if (plist->_head == NULL)
	{
		plist->_head = BuySListNode(x);
	}
	else
	{
		while (tail->_next != NULL)
		{
			tail = tail->_next;
		}

		newtail = BuySListNode(x);
		tail->_next = newtail;
	}
}
//头插
void SListPushFront(SList* plist, SLTDataType x)
{
	SListNode * newhead = BuySListNode(x);
	assert(plist);
	newhead->_next = plist->_head;
	plist->_head = newhead;

}
//尾删
void SListPopBack(SList* plist)
{
	SListNode*tail = plist->_head;
	SListNode*prev = NULL;
	assert(plist);
	if (plist->_head->_next == NULL)
	{
		free(plist->_head);
		plist->_head = NULL;
	}
	else
	{
		while (tail->_next != NULL)
		{
			prev = tail;
			tail = tail->_next;
		}
		free(tail);
		prev->_next = NULL;
	}
}
//头删
void SListPopFront(SList* plist)
{
	SListNode*newhead = plist->_head;
	assert(plist);
	if (plist->_head == NULL)
	{
		free(plist->_head);
		plist->_head = NULL;
	}
	else
	{
		plist->_head = newhead->_next;
		free(newhead);
		newhead = NULL;
	}

}
//首先先找到该节点
SListNode* SListFind(SList* plist, SLTDataType x)
{
	SListNode*cur = plist->_head;
	assert(plist);
	while (cur != NULL)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return cur;
}
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	SListNode * newnode = BuySListNode(x);
	assert(pos);
	newnode->_next = pos->_next;
	pos->_next = newnode;
}
// 在pos的前面进行插入
void SListEraseAfter(SListNode* pos)
{
	assert(pos && pos->_next);
	SListNode* next = pos->_next;
	SListNode* nextnext = next->_next;
	pos->_next = nextnext;
	free(next);
	next = NULL;

}
void SListPrint(SList* plist)
{
	SListNode* cur;
	assert(plist);
	cur = plist->_head;
	while (cur)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}

int main()
{
	SList s;
	SListInit(&s);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushBack(&s, 5);
	SListPrint(&s);

	SListPushFront(&s,0);
	   SListPrint(&s);

	SListPopBack(&s);
	   SListPrint(&s);

	SListPopFront(&s);
	   SListPrint(&s);

	SListNode* pos = SListFind(&s, 3);
	SListInsertAfter(pos, 30);
	SListPrint(&s);


	SListEraseAfter(pos);
	SListPrint(&s);
	SListDestory(&s);
}