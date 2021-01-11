#include <iostream>
using namespace std;

class Animal                                                  //定义基类Animal
{
public:
	//获取m_nAge属性值的函数
	int get_age(){ return m_nAge; }
	//获取m_nWeight属性值的函数
	int get_weight(){ return m_nWeight; }
	//设置m_nAge属性的函数
	void set_age(int param_age){ m_nAge = param_age; }
	//设置m_nWeight属性的函数
	void set_weight(int param_weight){ m_nWeight = param_weight; }
	//定义动物说话的函数
	void speak(){ cout << "animal language!" << endl; }
private:
	int m_nWeight;
	int m_nAge;
};

class Cat :public Animal                                  //定义派生类Cat
{
public:
	//设置m_strName属性的函数
	void set_name(string param_name);
	//定义猫说话的函数，该函数与基类中的speak()函数同名
	void speak(){ cout << "cat language: miaomiao!" << endl; }
private:
	string m_strName;
};
int main()
{
	Cat cat;                                                //定义派生类对象cat
	Animal *panimal = &cat;                              //定义基类指针并初始化为cat地址

	panimal->set_age(5);                                 //基类指针调用基类set_age()函数
	cout << "base type: age = "
		<< panimal->get_age() << endl;               //指针指针调用基类get_age()函数
	cat.speak();                                          //派生类对象调用speak()函数
	panimal->speak();                                    //基类指针调用speak()函数

	system("pause");
	return 0;
}
