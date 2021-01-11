#include <iostream>
#include <string>
using namespace std;

int int_div(int a, int b)                                 //实现整数相除的函数
{
	if (b == 0){
		throw 0;
		cout << "after throw!" << endl;
	}
	return a / b;
}
int main()
{
	int int_n1, int_n2;                                    //定义两个整型变量
	//循环多次读取数据，完成相除操作
	while (1){
		cout << "Please input two integers:";
		cin >> int_n1 >> int_n2;                         //输入两个整数
		try	{
			cout << "Maybe exception code:" << endl;
			cout << int_n1 << "/" << int_n2 << " = "
				<< int_div(int_n1, int_n2) << endl;   //除数非零显示相除结果
			cout << "in try, after div!" << endl;
		}
		catch (int)                                         //捕捉参数为整型的异常
		{
			cout << "exception:div 0!" << endl;       //异常处理代码
		}
		cout << "after try…catch!" << endl;;
	}

	return 0;
}
