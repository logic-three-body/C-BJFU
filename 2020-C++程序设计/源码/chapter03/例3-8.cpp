#include <iostream>
using namespace std;

class Animal                                               //定义基类
{
public:
	Animal(int con_weight, int con_age);             //声明带参构造函数
	~Animal()
	{
		cout << "Animal destructor!" << endl;
		system("pause");
	}
	int get_age(){ return m_nAge; }                   //获取m_nAge属性值
private:
	int m_nWeight, m_nAge;
};
Animal::Animal(int con_weight, int con_age)         //定义基类带参构造函数
{
	m_nWeight = con_weight;
	m_nAge = con_age;
	cout << "Animal constructor with param!" << endl;
}

class Cat :public Animal{                               //定义派生类
public:
	//声明带参构造函数
	Cat(string con_name, int con_weight, int con_age);
	~Cat(){ cout << "Cat destructor!" << endl; }    //定义析构函数
private:
	string m_strName;
};
//定义派生类带参的构造函数
Cat::Cat(string con_name, int con_weight, int con_age) :Animal(con_weight, con_age)
{
	m_strName = con_name;
	cout << "Cat constructor with param!" << endl;
}

int main()
{
	Cat cat("Persian", 3, 4);                          //定义派生类对象
	cout << "cat age = " << cat.get_age() << endl;//调用get_age()函数
	return 0;
}
