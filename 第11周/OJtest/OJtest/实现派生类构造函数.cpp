#include<iostream>
#include<cstring>
using namespace std;
class Base
{
private:
	int n;
public:
	Base(int a)
	{
		n = a;
	}
	void show()
	{
		cout << "n=" << n << endl;
	}

};
class A :public Base
{
private:
	int m;
public:
	A(int a, int b);//请实现该构造函数
	void showa()
	{
		show();
		cout << "m=" << m << endl;

	}

};
A::A(int a, int b):Base(a)
{
	m = b;
}

int main()
{
	A dobj(10, 20);
	dobj.showa();
	return 0;
}