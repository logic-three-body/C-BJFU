//product.cpp
#include "product.h"
#include <iostream>
using namespace std;

AbstractProduct::AbstractProduct()                  //定义AbstractProduct构造函数
{
}
AbstractProduct::~AbstractProduct()                //定义AbstractProduct析构函数
{
}
Product1::Product1()                                  //定义Product1构造函数
{
	cout << "product1 constructor!" << endl;
}
Product1::~Product1()                                 //定义Product1析构函数
{
}
void Product1::operation()                           //定义Product1操作函数
{
	cout << "product1 operation!" << endl;
}

Product2::Product2()                                   //定义Product2构造函数
{
	cout << "product2 constructor!" << endl;
}
Product2::~Product2()                                 //定义Product2析构函数
{
}
void Product2::operation()                          //定义Product2操作函数
{
	cout << "product2 operation!" << endl;
}
