#include <iostream>
using namespace std;
inline void func() //内联函数
{
	cout << "这是一个内联函数" << endl;
}
int main()
{
	func(); //内联函数调用
	system("pause");
	return 0;
}
