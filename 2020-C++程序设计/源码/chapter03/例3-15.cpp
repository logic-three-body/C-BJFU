#include <iostream>
using namespace std;

class Animal                                           //定义类Animal
{
public:
	//定义类Animal的构造函数
	Animal(int age) :m_nAge(age)  { cout << "Animal constructor!" << endl; }
protected:
	int m_nAge;                                     //成员m_nAge记录动物年龄
};
class Bird :public Animal                          //定义类Bird继承自Animal
{
public:
	Bird(int age, int fh) :Animal(age)          //定义类Bird的构造函数
	{
		cout << "Bird constructor!" << endl;
		m_nFlightAltitude = fh;
	}
	//定义获取鸟飞行高度的函数
	int get_flightaltitude() { return m_nFlightAltitude; }
private:
	int m_nFlightAltitude;
};

class Fish :public Animal                        //定义类Fish继承自Animal
{
public:
	Fish(int age, int speed) :Animal(age)     //定义类Fish的构造函数
	{
		cout << "Fish constructor!" << endl;
		m_nSwimSpeed = speed;
	}
	//定义获取鱼游速的函数
	int get_swimspeed() { return m_nSwimSpeed; }
private:
	int m_nSwimSpeed;
};

class WaterBird :public Bird, public Fish     //定义水鸟类
{
public:
	//定义水鸟类带参数的构造函数
	WaterBird(int b_age, int f_age, int fh, int speed) :Bird(b_age, fh),
		Fish(f_age, speed)
	{
		cout << "WaterBird constructor!" << endl;
	}
	void print_animalage()                      //定义打印动物年龄的函数
	{
		cout << "age = " << Bird::m_nAge << endl;
		cout << "age = " << Fish::m_nAge << endl;
	}
};

int main()
{
	WaterBird waterbird(5, 6, 20, 30);        //定义水鸟对象

	cout << "waterbird flight altitude: " << waterbird.get_flightaltitude()
		<< ", swimming speed:" << waterbird.get_swimspeed() << endl;

	waterbird.print_animalage();
	system("pause");
	return 0;
}
