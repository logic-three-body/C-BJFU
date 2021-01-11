//iterator.cpp
#include <iostream>
#include "aggregate.h"
#include "iterator.h"
using namespace std;

Iterator::Iterator()                                    //定义抽象迭代器的构造函数
{
}
Iterator::~Iterator()                                  //定义抽象迭代器的析构函数
{
}
//定义具体迭代器类的构造函数，首参数表示对哪个聚合类型数据进行迭代，第二个参数表示从哪里开始迭代
ConcreteIterator::ConcreteIterator(Aggregate *ag, int idx)
{
	m_ag = ag;
	m_idx = idx;
}
ConcreteIterator::~ConcreteIterator()             //定义具体迭代器的析构函数
{
}
Object ConcreteIterator::current_item()           //定义获取聚合数据中当前对象的函数
{
	return m_ag->get_item(m_idx);
}
//定义设置聚合数据首位置的函数
void ConcreteIterator::first()
{
	m_idx = 0;
}
//定义设置聚合数据中下一个位置的函数
void ConcreteIterator::next()
{
	if (m_idx < m_ag->get_size())
		m_idx++;
}
//定义判断是否迭代完毕的函数
bool ConcreteIterator::is_done()
{
	return (m_idx == m_ag->get_size());
}
