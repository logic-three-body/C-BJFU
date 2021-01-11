#include <iostream>
using namespace std;
class Date;                                              //声明Date类
class Time                                               //定义Time类，描述时分秒
{
public:
	Time(int con_hour, int con_minute, int con_second) //定义构造函数
	{
		m_nHour = con_hour;
		m_nMinute = con_minute;
		m_nSecond = con_second;

	}
	friend class Date;                                 //声明Date为Time的友元类
private:
	int m_nHour, m_nMinute, m_nSecond;
};
class Date                                               //定义Date类
{
public:
	Date(int con_year, int con_month, int con_day)//定义构造函数
	{
		m_nYear = con_year;
		m_nMonth = con_month;
		m_nDay = con_day;
	}
	void display_date_time(Time &ref_time);        //声明display_date_time()函数
private:
	int m_nYear, m_nMonth, m_nDay;
};
/*
* 定义display_date_time()函数，显示年月日、时分秒信息。由于Date为Time类的友元类，
* 则Date中的函数为Time类的友元函数，可以访问Time类的私有成员，
* 这里直接访问了私有成员：m_nHour、m_nMinute、m_nSecond
*/
void Date::display_date_time(Time &ref_time)
{
	cout << m_nYear << "-" << m_nMonth << "-" << m_nDay << " "
		<< ref_time.m_nHour << ":" << ref_time.m_nMinute
		<< ":" << ref_time.m_nSecond << endl;
}
int main()
{
	Time time(17, 30, 20);                          //定义Time对象
	Date date(2015, 3, 31);                         //定义Date对象
	date.display_date_time(time);                  //显示年月日、时分秒信息
	system("pause");
	return 0;
}
