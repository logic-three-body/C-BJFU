//proxy.h
#ifndef PROXY_H
#define PROXY_H

class Subject{                                           //定义抽象主体类
public:
	virtual ~Subject();
	virtual void request() = 0;
protected:
	Subject();
};
//定义抽象主体类的派生类，描述一个具体的主体
class ConcreteSubject :public Subject{
public:
	ConcreteSubject();
	~ConcreteSubject();
	void request();
};
class Proxy :public Subject{                         //定义代理类
public:
	Proxy();
	Proxy(Subject *sub);
	~Proxy();
	void request();
private:
	Subject *m_sub;                                    //定义一个指向主体的指针
};
#endif
