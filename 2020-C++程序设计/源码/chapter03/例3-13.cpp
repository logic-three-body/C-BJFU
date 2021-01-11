#include <iostream>
using namespace std;

class Date{                                                        //定义日期类
public:
	Date(int con_year, int con_month, int con_day);        //声明构造函数
	//显示年月日信息的函数print_date()
	void print_date(){ cout << m_nYear << "-" << m_nMonth << "-" << m_nDay << endl; }
private:
	int m_nYear, m_nMonth, m_nDay;
};
Date::Date(int con_year, int con_month, int con_day)     //定义日期类构造函数
{
	cout << "Date constructor!" << endl;
	m_nYear = con_year;
	m_nMonth = con_month;
	m_nDay = con_day;
}
class Bird                                                    //定义鸟类
{
public:
	Bird(int fh)                                            //定义鸟类带参数的构造函数
	{
		cout << "Bird constructor!" << endl;
		m_nFlightAltitude = fh;
	}
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
private:
	int m_nSwimSpeed;
};
class WaterBird :public Bird, public Fish              //定义水鸟类
{
public:
	//定义派生类构造函数，函数的前三个参数用于为本类数据成员m_iBirthday提供初值
	//m_iBirthday的初始化在初始化列表中完成
	WaterBird(int year, int month, int day, int fh, int speed) :Bird(fh),
		Fish(speed), m_iBirthday(year, month, day)
	{
		cout << "WaterBird constructor!" << endl;
	}
	void print_birthday()
	{
		m_iBirthday.print_date();
	}
private:
	//定义Date类对象为WaterBird类的数据成员
	Date m_iBirthday;
};
int main()
{
	WaterBird waterbird(2010, 5, 1, 20, 30);               //定义水鸟对象并提供参数
	cout << "waterbird birthday:";
	waterbird.print_birthday();
	system("pause");
	return 0;
}
