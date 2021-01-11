#include <iostream>
using namespace std;
//定义函数模板
template<typename T>
T add(T t1, T t2)
{
	return t1 + t2;
}
int main()
{
	cout << add(1, 2) << endl;  //传入int类型参数
	cout << add(1.2, 3.4) << endl; //传入double类型参数
	system("pause");
	return 0;
}
