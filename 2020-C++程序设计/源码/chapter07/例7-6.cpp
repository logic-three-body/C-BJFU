#include <iostream>
using namespace std;

class Example{                                                  //定义Example类
public:
	Example(){ cout << "Example constructor!" << endl; }
	~Example() { cout << "Example destructor!" << endl; }
};
class ZeroException{                                           //定义描述除零异常的类
public:
	ZeroException();
	~ZeroException();
	ZeroException(ZeroException &ref);
	const char *getmsg() { return msg; }
private:
	const char *msg;

};
ZeroException::ZeroException() :msg("div zero")          //ZeroException类构造函数
{
	cout << "ZeroException constructor!" << endl;
}
ZeroException::ZeroException(ZeroException &ref)      //ZeroException类拷贝构造函数
{
	msg = ref.msg;
	cout << "ZeroException cp constructor!" << endl;
}
ZeroException::~ZeroException()                          //ZeroException类析构函数
{
	cout << "ZeroException destructor!" << endl;
}

int int_div(int n1, int n2)                                //整数相除函数
{
	//定义Example类对象obj，该对象在抛出异常时会被析构
	Example obj;
	if (n2 == 0){
		throw ZeroException();
	}
	return n1 / n2;
}

int main()
{
	int int_n1, int_n2;                                     //定义两个整型变量

	while (1){                                                //循环多次读取数据，完成相除操作
		cout << "Please input two integers:";          //输入提示
		cin >> int_n1 >> int_n2;                          //输入两个整型数
		try{
			cout << "Maybe exception code:" << endl;  //提示可能出现异常的代码信息
			cout << int_n1 << "/" << int_n2 << " = "
				<< int_div(int_n1, int_n2) << endl;  //除数非零显示相除结果
			cout << "in try, after div!" << endl;
		}
		catch (ZeroException &divzero)                  //捕捉ZeroException类的异常
			//catch(ZeroException divzero)                 //捕捉ZeroException类的异常
		{
			cout << "exception:"
				<< divzero.getmsg() << endl;          //异常处理代码
		}
	}
	return 0;
}
