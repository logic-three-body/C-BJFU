#include<iostream>
#include<cstring>
using namespace std;
class Base
{
protected:
	int a;
public:
	Base(int x) :a(x)
	{
	}
};
class Base1 : virtual public Base
{
protected:
	int b;
public:
	Base1(int x, int y) : Base(y), b(x)
	{
	}
};
class Base2 : virtual public  Base
{
protected:
	int c;
public:
	Base2(int x, int y) : Base(y)
	{
		c = x;
	}
};
class Derived : public Base1, public Base2
{
protected:
	int d3;
public:
	Derived(int x, int y);        //请实现该函数
	void show()
	{
		cout << "a=" << a << endl;
		cout << "Base::a=" << Base::a << endl;
		cout << "Base1::a=" << Base1::a << endl;
		cout << "Base2::a=" << Base2::a << endl;
		cout << "b=" << b << endl;
		cout << "c=" << c << endl;
	}
};

Derived::Derived(int x, int y):Base(x+y),Base1(x,y),Base2(y,x)
{

}
int main()
{
	Derived dobj(10, 20);
	dobj.show();
	return 0;
}