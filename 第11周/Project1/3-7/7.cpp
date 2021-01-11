#include <iostream>
using namespace std;

class Animal                                             //定义基类
{
public:
	Animal(int con_weight, int con_age);          //声明带参数的构造函数
private:
	int m_nWeight;
	int m_nAge;
};
Animal::Animal(int con_weight, int con_age)    //定义基类带参数的构造函数
{
	m_nWeight = con_weight;
	m_nAge = con_age;
	cout << "Animal constructor with param!" << endl;
}
class Cat :public Animal
{                                                     //定义派生类
public:
	//声明派生类带参数的构造函数
	Cat(string con_name, int con_weight, int con_age);
private:
	string m_strName;
};
/*
* 定义派生类带参数的构造函数，三个参数中，第一个参数用于对派生类私有成员m_strName进行初始化，
* 第二个、第三个参数用于基类数据成员的初始化
*/
//Cat::Cat(string con_name, int con_weight, int con_age) :Animal(con_weight, con_age)
//{
//	m_strName = con_name;
//	cout << "Cat constructor with param!" << endl;
//}
Cat::Cat(string con_name, int con_weight, int con_age) : Animal(con_weight, con_age),m_strName(con_name)
{
	/*m_strName = con_name;*/
	cout << "Cat constructor with param!" << endl;
}
int main()
{
	Cat cat("Persian", 5, 7);                  //创建派生类对象
	system("pause");
	return 0;
}
