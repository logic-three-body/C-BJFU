#include <iostream>
using namespace std;

class Animal                                            //定义基类Animal
{
public:
	//定义虚函数speak()
	virtual void speak(){ cout << "animal language!" << endl; }
};
class Cat :public Animal                             //定义派生类Cat
{
public:
	//定义Cat类自己的虚函数speak()
	virtual void speak(){ cout << "cat language: miaomiao!" << endl; }
};
int main()
{
	Cat cat;                                           //定义派生类对象cat
	Animal *panimal = &cat;                         //定义基类指针并初始化为cat地址
	Animal &ref = cat;                               //定义基类引用，初始化为cat
	panimal->speak();                                //通过panimal指针调用speak()函数
	ref.speak();                                      //通过引用ref调用speak()函数
	system("pause");
	return 0;
}
