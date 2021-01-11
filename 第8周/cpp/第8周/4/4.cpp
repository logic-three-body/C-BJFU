#include <iostream>
using namespace std;

class Car                                            //定义类Car
{
	//成员函数
public:
	void disp_mems_value();                       //声明用于显示数据成员值的函数
	//数据成员
private:
	int m_nWheels;
	int m_nSeats;
	int m_nLength;
};
void Car::disp_mems_value()                      //类成员函数disp_mems_value()的实现
{
	cout << "wheels = " << m_nWheels << endl;
	cout << "seats = " << m_nSeats << endl;
	cout << "length = " << m_nLength << endl;
}
int main()
{
	Car mycar;                                     //定义类对象mycar
	mycar.disp_mems_value();                //调用函数显示数据成员值
	system("pause");
	return 0;
}
