#include <iostream>                                   
#include <string>
using namespace std;

class Animal                                                //定义基类Animal
{
public:
	//设置m_nWeightBase属性的成员函数
	void set_weight(int weight){ m_nWeightBase = weight; }
	//获取m_nWeightBase值的成员函数
	int get_weight(){ return m_nWeightBase; }
	//设置m_nAgeBase属性的成员函数
	void set_age(int age){ m_nAgeBase = age; }
protected:
	int m_nAgeBase;                                        //定义保护成员m_nAgeBase
private:
	int m_nWeightBase;                                    //定义私有成员m_nWeightBase
};

class Cat :protected Animal                             //通过保护继承，定义派生类Cat
{
public:
	Cat(string con_name) :m_strName(con_name){}
	//定义函数set_print_weight()，该函数访问基类成员函数set_weight()、get_weight()
	void set_print_weight()
	{
		set_weight(6);
		cout << m_strName << " weight = " << get_weight() << endl;
	}
private:
	string m_strName;                                   //派生类的私有成员
};

class PersianCat :protected Cat                       //保护继承的派生类PersianCat
{
public:
	PersianCat() :Cat("persian cat"){  }             //定义构造函数
	//函数persian_set_print_age()访问Animal类中的数据成员m_nAgeBase和set_age()函数
	void persian_set_print_age()
	{
		set_age(5);                                  //直接调用从基类中保护继承的函数
		cout << "PersianCat, age = " << m_nAgeBase << endl;
	}
};
int main()
{
	PersianCat persian_cat;                          //定义PersianCat对象
	persian_cat.persian_set_print_age();          //调用显示m_nAgeBase值的成员函数
	system("pause");
	return 0;
}
