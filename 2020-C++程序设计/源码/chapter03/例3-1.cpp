
#include <iostream>                                   
#include <string>
using namespace std;
class Animal                                               //定义Animal类
{
public:
	void speak()                                           //成员函数
	{
		cout << "animal language!" << endl;
	}
};
class Cat :public Animal                                  //定义Animal的派生类Cat
{
public:
	Cat(string con_name) :m_strName(con_name){}       //构造函数
	void print_name()                                     //成员函数，显示猫的名称
	{
		cout << "cat name: " << m_strName << endl;
	}
private:
	string m_strName;                                      //数据成员，记录猫名称
};
int main()
{
	Cat cat("Persian");                                  //定义派生类对象
	cat.print_name();
	cat.speak();                                          //派生类对象使用基类成员函数
	system("pause");
	return 0;
}
