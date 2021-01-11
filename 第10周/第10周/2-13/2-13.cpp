#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
	Car();
	Car(string con_carname, int con_seats);      //带参数的构造函数
	Car(Car &refcar);                                //拷贝构造函数
	~Car();                                            //析构函数
	Car get_carinfo();                               //获取对象信息的函数
	void print();
private:
	string m_strCarName;
	int m_nSeats;
};
Car::Car()                                           //定义无参数的构造函数
{
	cout << "constructor!" << endl;
}
Car::Car(string con_carname, int con_seats)   //定义带参数的构造函数
{
	cout << "Car constructor with params!" << endl;
	m_strCarName = con_carname;
	m_nSeats = con_seats;
}

Car::Car(Car &con_refcar)                      //定义拷贝构造函数
{
	cout << "Car cp constructor!" << endl;
	m_strCarName = con_refcar.m_strCarName;
	m_nSeats = con_refcar.m_nSeats;
}
Car::~Car()                                       //定义析构函数
{
	static int i = 0;
	cout << "destructor is called!" << endl;
	if (i == 3)
		system("pause");
	i++;
}
Car Car::get_carinfo()                        //定义获取对象信息的函数
{
	Car tmp(m_strCarName, m_nSeats);

	return tmp;                                //返回值为类对象
}
void Car::print()                             //打印对象属性值
{
	cout << "carname: " << m_strCarName << ", "
		<< "seats： " << m_nSeats << endl;
}
int main()
{
	Car mynewcar("my first car", 4);        //通过带参数的构造函数定义类对象
	Car ret;                                     //通过无参数的构造函数定义类对象
	//调用成员函数get_carinfo()，类对象接收返回值
	ret = mynewcar.get_carinfo();
	ret.print();                                 //显示属性值

	return 0;
}
