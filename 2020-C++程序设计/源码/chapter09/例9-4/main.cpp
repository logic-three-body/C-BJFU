#include <iostream>
#include "aggregate.h"
#include "iterator.h"
using namespace std;

int main()
{
	//定义一个具体的聚合类型，由ag指向
	Aggregate *ag = new ConcreteAggregate();
	//定义迭代器it，操作ag指向的聚合类型数据
	Iterator *it = new ConcreteIterator(ag);
	//使用迭代器依次操作聚合类型中的对象
	for (; !(it->is_done()); it->next()){
		cout << it->current_item() << endl;
	}
	system("pause");
	return 0;
}
