#include <iostream>
#include <string>
using namespace std;

int int_div(int a, int b)                                //实现整数相除的函数
{
	if (b == 0){                                           //若除数为0，抛出异常
		throw 0;
	}
	return a / b;
}
int main()
{
	int int_n1, int_n2;                                   //定义两个整型变量
	while (1){                                              //循环多次读取数据，完成相除操作
		cout << "Please input two integers:";
		cin >> int_n1 >> int_n2;                         //输入两个整型数
		try	{
			cout << "Maybe exception code:" << endl;
			cout << int_n1 << "/" << int_n2 << " = "
				<< int_div(int_n1, int_n2) << endl;  //除数非零显示相除结果
		}
		catch (int)                                        //捕捉整型异常
		{
			cout << "exception:div 0!" << endl;      //异常处理代码
		}
	}
	system("pause");
	return 0;
}
