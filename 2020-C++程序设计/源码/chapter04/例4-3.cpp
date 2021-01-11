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
	friend A operator+(const A& a1, const A& a2); //重载为类的友员函数
	friend A operator-(const A& a1, const A& a2); //重载为类的友员函数
};
void A::show() const
{
	cout << "(x,y) = " << "(" << x << "," << y << ")" << endl;
}
A operator+(const A& a1, const A& a2)
{
	return A(a1.x + a2.x, a1.y + a2.y);
}
A operator-(const A& a1, const A& a2)
{
	return A(a1.x - a2.x, a1.y - a2.y);
}
int main()
{
	A a1(1, 2);
	A a2(4, 5);
	A a;
	cout << "a1: ";
	a1.show();
	cout << "a2: ";
	a2.show();
	a = a1 + a2;
	cout << "a: "; a.show();

	a = a1 - a2;
	cout << "a: "; a.show();

	system("pause");
	return 0;
}
