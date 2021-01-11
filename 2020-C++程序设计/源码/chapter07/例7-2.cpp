#include <iostream>
#include <string>
using namespace std;

int main()
{
	int int_n1, int_n2;                                //定义两个整型变量
	cout << "Please input two integers:";          //输入提示
	cin >> int_n1 >> int_n2;                          //输入两个整数
	try
	{
		cout << "Maybe exception code:" << endl;  //提示可能出现异常的代码
		if (int_n2 == 0)                               //除数为0则抛出异常
		{
			throw 0;
		}
		else
		{
			cout << int_n1 << "/" << int_n2 << " = "
				<< (int_n1 / int_n2) << endl;     //除数非零显示相除结果
		}
	}
	catch (int)                                           //捕捉参数为整型的异常
	{
		cout << "exception:div 0!" << endl;        //异常处理代码
	}
	system("pause");
	return 0;
}
