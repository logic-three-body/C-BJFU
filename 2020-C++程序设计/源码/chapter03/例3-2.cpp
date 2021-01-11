#include <iostream>                                   
#include <string>
using namespace std;

class Animal                                           //定义基类Animal
{
public:
	//设置m_nWeightBase属性的成员函数
	void set_weight(int weight){ m_nWeightBase = weight; }
	//获取m_nWeightBase 值的成员函数
	int get_weight(){ return m_nWeightBase; }
	//设置m_nAgeBase属性的成员函数
	void set_age(int age){ m_nAgeBase = age; }
protected:
	int m_nAgeBase;                                  //定义保护成员m_nAgeBase
private:
	int m_nWeightBase;                              //定义私有成员m_nWeightBase
};
class Cat :public Animal                            //通过公有继承，定义派生类Cat
{
public:
	Cat(string con_name) :m_strName(con_name){}
	//定义函数print_age()，该函数访问基类成员m_nAgeBase
	void print_age(){ cout << m_strName << ", age = " << m_nAgeBase << endl; }
private:
	string m_strName;                              //派生类的私有成员
};
int main()
{
	Cat cat("Persian");                           //定义派生类对象cat
	cat.set_age(5);                               //派生类对象调用从基类继承的公有成员函数
	cat.set_weight(6);                            //派生类对象调用从基类继承的公有成员函数
	cat.print_age();                              //派生类对象调用自己的公有函数
	cout << "cat weight = " << cat.get_weight() << endl;
	system("pause");
	return 0;
}
