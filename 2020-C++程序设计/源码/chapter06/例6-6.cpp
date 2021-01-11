#include <iostream>
using namespace std;
int main()
{
	float f = 20.2; //定义一个float类型变量

	//设置以科学计数法输出，所用字母均是大写
	cout.setf(ios::scientific | ios::uppercase);
	cout << "f = " << f << endl;

	//用flags()函数获取当前流状态标志
	cout << "第一次获取流状态标志：" << cout.flags() << endl;
	cout.flags(ios::showpos);    //将先前的状态标志都清除，设置showpos标志，

	//再次调用flags()获取当前流状态标志
	cout << "第二次获取流状态标志：" << cout.flags() << endl;
	cout << "设置showpos后，f = " << f << endl;
	cout.unsetf(ios::showpos); //取消showpos标志设置
	cout << "unsetf后, f = " << f << endl;
	system("pause");
	return 0;
}
