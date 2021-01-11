#include <iostream>
#include <string>
using namespace std;
int int_div(int a, int b)                                //实现整数相除的函数
{
	if (b == 0){
		throw 0;
	}
	return a / b;
}
void exception_handler(int n1, int n2)
{
	try{
		cout << "Maybe exception code:" << endl;
		cout << n1 << "/" << n2 << " = "
			<< int_div(n1, n2) << endl;               //除数非零显示相除结果
		cout << "in try, after div!" << endl;
	}
	catch (int n)                                          //捕捉参数为整型的异常
	{
		cout << "exception:div "
			<< n << "!" << endl;                       //异常处理代码
		throw n;                                           //重新抛出异常  
	}
}
int main()
{
	int int_n1, int_n2;                                  //定义两个整型变量

	while (1){                                             //循环多次读取数据，完成相除操作
		cout << "Please input two integers:";
		cin >> int_n1 >> int_n2;

		try{
			exception_handler(int_n1, int_n2);
		}
		catch (int)
		{
			cout << "outter try-catch!" << endl;    //接收第23行重抛的异常
		}
	}
	return 0;
}
