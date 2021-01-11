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
	A operator+(const A& a) const; //重载+运算符
	A operator- (const A& a) const; //重载-运算符
};
//类成员函数的实现
void A::show() const  //show()函数的实现
{
	cout << "(x,y) = " << "(" << x << "," << y << ")" << endl;
}

A A::operator+(const A& a) const //重载+运算符的实现
{
	return A(x + a.x, y + a.y);
}

A A::operator-(const A& a) const //重载-运算符的实现
{
	return A(x - a.x, y - a.y);
}
//main()函数调用
int main()
{
	A a1(1, 2);
	A a2(4, 5);
	A a;
	cout << "a1: ";
	a1.show();
	cout << "a2: ";
	a2.show();
	a = a1 + a2;  //实现两个对象相加
	cout << "a: ";
	a.show();
	a = a1 - a2; //实现两个对象相减
	cout << "a: ";
	a.show();
	system("pause");
	return 0;
}
