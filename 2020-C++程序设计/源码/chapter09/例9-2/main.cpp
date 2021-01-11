#include <iostream>
#include "product.h"
#include "factory.h"
using namespace std;

int main()
{
	AbstractFactory *fac = new Factory();            //创建简单工厂类
	AbstractProduct *p1 = fac->create_product(1);  //通过简单工厂生产产品1
	AbstractProduct *p2 = fac->create_product(2);  //通过简单工厂生产产品2
	p1->operation();                                     //产品1执行相应操作
	p2->operation();                                     //产品2执行相应操作
	delete fac;
	delete p1;
	delete p2;
	system("pause");
	return 0;
}
