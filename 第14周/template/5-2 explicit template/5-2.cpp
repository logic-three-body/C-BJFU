#include <iostream>
using namespace std;
template<typename T>
T add(T t1, T t2)
{
	return t1 + t2;
}
template int add<int>(int t1, int t2); //显式实例化为int类型
int main()
{
	int a = 'c';
	cout << a << endl;
	cout << add<int>(10, 'B') << endl;  //函数模板调用
	cout << add(1.2, 3.4) << endl;
	system("pause");
	return 0;
}
