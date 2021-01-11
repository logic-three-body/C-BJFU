#include <iostream>
using namespace std;

class Bird{                                                  //定义鸟类
public:
	Bird(int fh)                                            //定义鸟类带参数的构造函数
	{
		cout << "Bird constructor!" << endl;
		m_nFlightAltitude = fh;
	}
	//定义鸟在天空飞的成员函数
	void fly_in_sky()	{ cout << "bird fly in sky!" << endl; }
	//定义鸟呼吸的成员函数
	void breath() { cout << "bird breath!" << endl; }
	//定义获取鸟飞行高度的成员函数
	int get_flightaltitude() { return m_nFlightAltitude; }
private:
	int m_nFlightAltitude;
};
class Fish                                                  //定义鱼类
{
public:
	Fish(int speed)                                      //定义鱼类带参数构造函数
	{
		cout << "Fish constructor!" << endl;
		m_nSwimSpeed = speed;
	}
	//定义鱼在水里游的成员函数
	void swim_in_water()	{ cout << "fish swim in water!" << endl; }
	//定义鱼呼吸的成员函数
	void breath() { cout << "fish breath!" << endl; }
	//定义获取游速的成员函数
	int get_swimspeed() { return m_nSwimSpeed; }
private:
	int m_nSwimSpeed;
};
//定义派生类-水鸟类，继承自基类Bird、Fish
class WaterBird :public Bird, public Fish
{
public:
	//定义水鸟类带参数的构造函数，其中调用基类的构造函数
	WaterBird(int fh, int speed) :Bird(fh), Fish(speed)
	{
		cout << "WaterBird constructor!" << endl;
	}
	//定义水鸟行为的成员函数
	void fly_swim() { cout << "waterbird cat fly and swim!" << endl; }
	//定义水鸟呼吸的成员函数
	void breath(){ cout << "waterbird breath!" << endl; }
};
int main()
{
	WaterBird waterbird(20, 30);                         //定义水鸟对象
	//调用get_flightaltitude()函数，显示水鸟飞行高度
	cout << "waterbird flight altitude: " << waterbird.get_flightaltitude();
	//调用get_swimspeed()函数，显示水鸟游速
	cout << ", swimming speed:" << waterbird.get_swimspeed() << endl;
	system("pause");
	return 0;
}
