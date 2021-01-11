//iterator.h
#ifndef ITERATOR_H
#define ITERATOR_H
class Aggregate;
typedef int Object;
class Iterator{                                         //定义抽象迭代器类
public:
	virtual ~Iterator();
	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool is_done() = 0;
	virtual Object current_item() = 0;
protected:
	Iterator();
};
//定义抽象迭代器的派生类，表示一个实际可操作的迭代器
class ConcreteIterator :public Iterator{
public:
	//声明迭代器的构造函数，首参数为要进行迭代的聚合类型指针
	ConcreteIterator(Aggregate *ag, int idx = 0);
	~ConcreteIterator();
	void first();
	void next();
	bool is_done();
	Object current_item();
private:
	Aggregate *m_ag;
	int m_idx;
};
#endif