#include <iostream>
using namespace std;

class ZeroException{                                    //定义描述除零异常的类
public:
	ZeroException() :msg("div zero!"){}              //构造函数
	const char *getmsg() { return msg; }            //获取msg信息
private:
	const char *msg;
};
int int_div(int n1, int n2)
{
	if (n2 == 0){
		throw ZeroException();                        //抛出异常类对象
	}
	return n1 / n2;
}

int main()
{
	int int_n1, int_n2;                                  //定义两个整型变量

	while (1){                                             //循环多次读取数据，完成相除操作
		cout << "Please input two integers:";        //输入提示
		cin >> int_n1 >> int_n2;                        //输入两个整数
		try	{
			cout << "Maybe exception code:" << endl;
			cout << int_n1 << "/" << int_n2 << " = "
				<< int_div(int_n1, int_n2) << endl;//除数非零显示相除结果
			cout << "in try, after div!" << endl;
		}
		catch (ZeroException divzero)                  //捕捉异常
		{
			cout << "exception:"
				<< divzero.getmsg() << endl;         //异常处理代码
		}
	}
	return 0;
}
