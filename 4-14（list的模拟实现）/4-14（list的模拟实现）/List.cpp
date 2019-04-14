#include"list.h"

void  TestList()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);

	List<int>::iterator it = l.begin();

}
int main()
{
	TestList();
	return 0;
}
