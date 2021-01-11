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
		cout << "n=" << n << endl;
	}
	Base();

};

Base::Base()
{

}
class A :public Base
{
private:
	int m;
	Base obj;
public:
	A(int a, int b, int c);//请实现该构造函数

};

A::A(int a, int b, int c) :Base(a),obj(c),m(b)
{
	/*Base::Base(c);*/

	cout << "m=" << b << endl;
}



int main()
{
	A dobj(10, 20, 30);
	return 0;
}