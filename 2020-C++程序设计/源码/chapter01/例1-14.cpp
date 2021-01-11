#include <iostream>
using namespace std;
void func1(const int *x) //常量指针
{
	cout << "const int*: " << *x << endl;
}
void func1(int *x) //普通指针
{
	cout << "int*: " << *x << endl;
}
void func2(const int &x) //常引用
{
	cout << "const int&: " << x << endl;
}
void func2(int &x) //普通引用
{
	cout << "int&: " << x << endl;
}
int main()
{
	const int a = 1;
	int b = 2;
	func1(&a); //常量参数
	func1(&b); //非常量参数

	func2(a);  //常量参数
	func2(b);  //非常量参数
	system("pause");
	return 0;
}
