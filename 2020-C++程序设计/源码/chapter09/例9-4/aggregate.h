//aggregate.h
#ifndef AGGREGATE_H
#define AGGREGATE_H
//把int类型更名为Object，本聚合类型中的对象为int类型
typedef int Object;
class Iterator;                                         //声明迭代器类型
class Aggregate{                                       //定义抽象聚合类型
public:
	virtual ~Aggregate();
	virtual Iterator *create_iterator() = 0;     //声明生成迭代器的接口
	virtual Object get_item(int idx) = 0;
	virtual int get_size() = 0;
protected:
	Aggregate();
};
//定义抽象聚合类的派生类，表示具体的某个聚合类型
class ConcreteAggregate :public Aggregate{
public:
	//定义枚举数据，表示聚合中有效数据的个数
	enum{ SIZE = 5 };
	ConcreteAggregate();
	~ConcreteAggregate();
	Iterator *create_iterator();
	Object get_item(int idx);
	int get_size();
private:
	Object m_objs[SIZE];                             //聚合类型中的具体数据
};
#endif