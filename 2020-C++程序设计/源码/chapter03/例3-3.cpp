#include <iostream>                                   
#include <string>
using namespace std;

class Animal                              //定义基类Animal
{
public:
	//设置m_nWeightBase属性的成员函数
	void set_weight(int weight){ m_nWeightBase = weight; }
	//获取m_nWeightBase值的成员函数
	int get_weight(){ return m_nWeightBase; }
	//设置m_nAgeBase属性的成员函数
	void set_age(int age){ m_nAgeBase = age; }
protected:
	int m_nAgeBase;                            //定义保护成员m_nAgeBase
private:
	int m_nWeightBase;                        //定义私有成员m_nWeightBase
};
class Cat :private Animal                    //通过私有继承，定义派生类Cat
{
public:
	Cat(string con_name) :m_strName(con_name){}
	//定义函数set_print_age()，该函数访问基类公有成员函数set_age()和保护成员m_nAgeBase
	void set_print_age()
	{
		set_age(5);                           //调用基类的成员函数
		cout << m_strName << " age = " << m_nAgeBase << endl;
	}
	//定义函数set_print_weight()，该函数访问基类公有成员函数set_weight()、get_weight()
	void set_print_weight()
	{
		set_weight(6);                      //调用基类的成员函数   
		cout << m_strName << ", weight = " << get_weight() << endl;
	}
private:
	string m_strName;                        //派生类的私有成员
};
int main()
{
	Cat cat("Persian");                     //定义派生类对象cat
	cat.set_print_age();
	cat.set_print_weight();                //派生类对象调用自己的公有函数
	system("pause");
	return 0;
}
