#include <iostream>
using namespace std;

class Bird                                                  //定义鸟类
{
public:
	//定义鸟呼吸的成员函数
	void breath()   { cout << "bird breath!" << endl; }
};
class Fish                                                 //定义鱼类
{
public:
	//定义鱼呼吸的成员函数
	void breath()   { cout << "fish breath!" << endl; }
};
class WaterBird :public Bird, public Fish         //定义水鸟类
{
public:
	//定义水鸟行为的成员函数
	void fly_swim() { cout << "waterbird cat fly and swim!" << endl; }
};

int main()
{
	WaterBird waterbird;                            //定义水鸟对象
	//错误，由于WaterBird继承自两个基类，两个基类中存在同名函数breath()
	//水鸟类对象调用breath()函数时产生调用基类同名函数的二义性
	waterbird.breath();
	system("pause");
	return 0;
}
