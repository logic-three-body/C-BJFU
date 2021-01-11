#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double d = sqrt(2.0);
	cout << "精度设置：" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout.precision(i);  //设置不同的精度
		cout << d << endl;
	}
	cout << "当前精度为：" << cout.precision() << endl;

	cout << "当前域宽：" << cout.width() << endl;
	cout.width(6);  //默认是右对齐
	cout << d << endl;

	cout << "当前填充字符：" << cout.fill() << "|" << endl;
	cout.width(10);  //设置域宽，精度设置一次就不必重新设置
	cout << setfill('*') << d << endl; //setfill()函数可以直接插入流中
	system("pause");
	return 0;
}
