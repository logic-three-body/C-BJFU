#include <iostream>
using namespace std;

class Base                                               //定义基类Base
{
protected:
	int n_base;                                        //定义数据成员n_base
};
class Derive :public Base                             //定义公有派生类Derive
{
public:
	//定义disp_addr()成员函数，显示继承自基类的数据成员和派生类私有数据成员的地址信息
	void disp_addr() {
		cout << "n_base addr:" << &n_base << endl;
		cout << "n_derive addr:" << &n_derive << endl;
	}
private:
	int n_derive;
};
int main()
{
	Derive obj;                                        //定义派生类对象
	obj.disp_addr();                                  //调用disp_addr()函数
	//通过sizeof运算符求obj占用的字节数
	cout << "sizeof(obj) = " << sizeof(obj) << endl;
	system("pause");
	return 0;
}
