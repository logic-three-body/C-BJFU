//factory.cpp
#include <iostream>
#include "factory.h"
#include "product.h"
using namespace std;

AbstractFactory::AbstractFactory()                 //定义抽象工厂类构造函数
{
}
AbstractFactory::~AbstractFactory()                //定义抽象工厂类析构函数
{
}
Factory::Factory()                                    //定义简单工厂类构造函数
{
	cout << "factory constructor!" << endl;
}
Factory::~Factory()                                   //定义简单工厂类析构函数
{
}
//定义create_product()函数，该函数根据参数创建不同产品对象
AbstractProduct *Factory::create_product(int type)
{
	switch (type){
	case 1:	return new Product1();
	case 2: return new Product2();
	}
}
