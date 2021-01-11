#include <iostream>
using namespace std;

class Car                                         //定义类Car
{
	//成员函数
public:
	void disp_welcomemsg();                    //声明disp_welcomemsg()函数
	int get_wheels();                           //声明get_wheels()函数
	void set_wheels(int);                      //声明set_wheels()函数
	//数据成员
private:
	int m_nWheels;
};
void Car::disp_welcomemsg()                  //类成员函数disp_welcomemsg()的实现
{
	cout << "Welcome to the car world!" << endl;
}
int Car::get_wheels()                        //类成员函数get_wheels()的实现，获取车轮数
{
	return m_nWheels;
}
void Car::set_wheels(int n)                 //类成员函数set_wheels()实现，设置车轮数
{
	m_nWheels = n;
}
int main()
{
	Car mycar;                                 //定义类对象mycar
	mycar.disp_welcomemsg();                //访问成员函数，显示欢迎信息
	mycar.set_wheels(4);                     //访问成员函数，设置车轮数量
	//访问成员函数，显示车轮数量
	cout << "wheels = " << mycar.get_wheels() << endl;
	system("pause");
	return 0;
}
