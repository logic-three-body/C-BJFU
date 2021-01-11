//proxy.cpp
#include <iostream>
#include "proxy.h"
using namespace std;

Subject::Subject()                                    //定义抽象主体类的构造函数
{
}
Subject::~Subject()                                  //定义抽象主体类的析构函数
{
}
ConcreteSubject::ConcreteSubject()               //定义真实主体类的构造函数
{
}
ConcreteSubject::~ConcreteSubject()              //定义真实主体类的析构函数
{
}
void ConcreteSubject::request()                    //真实主体类要完成的操作
{
	cout << "ConcreteSubject request!" << endl;
}

Proxy::Proxy()                                        //定义代理类构造函数
{
}
//代理类构造函数，参数为某个主体的指针
Proxy::Proxy(Subject *sub)
{
	m_sub = sub;
}
Proxy::~Proxy()                                       //定义代理类析构函数
{
}
void Proxy::request()                                //通过代理实现主体需要完成的操作
{
	cout << "Proxy request!" << endl;
	m_sub->request();
}
