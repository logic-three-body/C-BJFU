#include <iostream>
using namespace std;

class Animal                                       //定义基类Animal
{
public:
	//基类speak()函数
	void speak(){ cout << "animal language!" << endl; }
};
class Cat :public Animal                         //定义派生类Cat
{
public:
	//定义与基类同名的函数speak()
	void speak(){ cout << "cat language: miaomiao!" << endl; }
};
int main()
{
	Cat cat;                                          //定义派生类对象cat
	Animal *panimal = &cat;                       //定义基类指针并指向派生类对象
	panimal->speak();                              //通过指针调用speak()函数
	system("pause");
	return 0;
}
