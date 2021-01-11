//aggregate.cpp
#include <iostream>
#include "aggregate.h"
#include "iterator.h"
using namespace std;

Aggregate::Aggregate()                               //定义抽象聚合类型的构造函数
{
}
Aggregate::~Aggregate()                              //定义抽象聚合类型的析构函数
{
}
ConcreteAggregate::ConcreteAggregate()            //定义具体聚合类型的构造函数
{
	//向聚合类型中填充具体数据，数量为SIZE（5）个，保存在int类型的数组中
	for (int i = 0; i < SIZE; i++)
		m_objs[i] = i;
}
ConcreteAggregate::~ConcreteAggregate()           //定义具体聚合类型的析构函数
{
}
//定义生成迭代器的函数
Iterator *ConcreteAggregate::create_iterator()
{
	return new ConcreteIterator(this);
}
//定义从聚合类型中获取具体元素的函数
Object ConcreteAggregate::get_item(int idx)
{
	if (idx < this->get_size())
		return m_objs[idx];
	return -1;
}
int ConcreteAggregate::get_size()                   //定义获取聚合中有效数据个数的函数
{
	return SIZE;
}
