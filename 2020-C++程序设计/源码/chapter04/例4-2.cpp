#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class A
{
private:
	int x;
	int y;
public:
	A(int x1 = 0, int y1 = 0) :x(x1), y(y1){}
	void show() const; //输出数据
	A operator++();  //重载前置++
	A operator++(int); //重载后置++
};

void A::show() const
{
	cout << "(x,y) = " << "(" << x << "," << y << ")" << endl;
}
A A::operator++()  //前置++实现
{
	++x;
	++y;
	return *this;
}
A A::operator++(int) //后置++实现
{
	A a = *this;
	++(*this);  //调用已经实现的前置++
	return a;
}
int main()
{
	A a1(1, 2), a2(3, 4);
	(a1++).show();
	(++a2).show();

	system("pause");
	return 0;
}
