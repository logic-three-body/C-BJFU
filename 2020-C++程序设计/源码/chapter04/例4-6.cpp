#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Internet
{
public:   //为了后面输出方便，成员权限设置成为public
	char* name;
	char* url;
public:
	Internet(char* name, char* url); //构造函数
	Internet(Internet& temp); //拷贝构造函数
	~Internet()
	{
		delete[]name;
		delete[]url;
	}
	Internet& operator= (Internet& temp); //赋值运算符重载
};

//类Internet成员函数的实现
Internet::Internet(char* name, char* url)  //构造函数实现
{
	this->name = new char[strlen(name) + 1];
	this->url = new char[strlen(url) + 1];
	if (name)
		strcpy(this->name, name);
	if (url)
		strcpy(this->url, url);
}

Internet::Internet(Internet& temp)  //拷贝构造函数实现
{
	this->name = new char[strlen(temp.name) + 1];
	this->url = new char[strlen(temp.url) + 1];
	if (name)
		strcpy(this->name, temp.name);
	if (url)
		strcpy(this->url, temp.url);
}

Internet& Internet:: operator= (Internet& temp)
{
	delete[]name;
	delete[]url;  //先释放原来空间，再重新申请
	this->name = new char[strlen(temp.name) + 1];
	this->url = new char[strlen(temp.url) + 1];
	if (name)
		strcpy(this->name, temp.name);
	if (url)
		strcpy(this->url, temp.url);

	return *this;
}

int main()
{
	Internet a("传智播客", "http://net.itcast.cn/");
	cout << "a对象： " << a.name << " " << a.url << endl;

	Internet b(a);  //用a对象初始化b，调用的是拷贝构造函数
	cout << "b对象： " << b.name << " " << b.url << endl;

	Internet c("黑马训练营", "http://www.itheima.com/");
	cout << "c对象： " << c.name << " " << c.url << endl;

	b = c; //调用赋值重载函数
	cout << "b对象： " << b.name << " " << b.url << endl;
	system("pause");
	return 0;
}
