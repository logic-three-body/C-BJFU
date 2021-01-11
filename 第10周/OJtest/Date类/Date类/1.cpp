#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int isLeapYear(int year); //闰年判断
int yeard(int y);//返回该年的天数 
int monthx(int m1, int y1);//返回该月的天数 
class Date
{
public:

	Date(int d = 0, int m = 0, int y = 0, int d1 = 1, int m1 = 1, int y1 = 1901); //构造函数 //初始化

	int get_day() const; // 返回day

	int get_month() const; //返回month

	int get_year() const; // 返回year

	static void set_default(int, int, int); //设置default_date

	static int get_default_day(); //返回缺省day

	static int get_default_month(); //返回缺省month

	static int get_default_year(); //返回缺省year

	Date & add_year(int n); //加n年

	Date & add_month(int n); //加n月，考虑超过12月

	Date & add_day(int n); //加n天，考虑进位月和年，考虑闰年

private:

	int day, month, year;

	static Date default_date; //初始化为 1901年1月1日

};


Date Date::default_date(1, 1, 1901);
Date::Date(int d, int m, int y, int d1, int m1, int y1)
{
	day = d;
	month = m;
	year = y;
	default_date.day = d1;
	default_date.month = m1;
	default_date.year = y1;
}
int Date::get_day() const
{
	return day;
}
int Date::get_month() const
{
	return month;
}
int Date::get_year() const
{
	return year;
}
void Date::set_default(int x, int y, int z)//修改默认值
{
	default_date.day = x;
	default_date.month = y;
	default_date.year = z;
}
int Date::get_default_day()
{
	return default_date.day;
}
int Date::get_default_month()
{
	return default_date.month;
}
int  Date::get_default_year()
{
	return default_date.year;
}
Date & Date::add_year(int n)//加n年
{
	year += n;
	return *this;
}
Date & Date::add_month(int n)
{
	int remain = n;
	while (remain > 0) {
		month++;
		remain--;
		if (month == 13) {  //超过一年判断
			month = 1;
			year++;
		}
	}
	return *this;
}
Date & Date::add_day(int n)
{
	int remain = n;//还剩的天数
	 //最后加天数 
	while (remain > 0) {
		day++;
		remain--;
		if (day == monthx(month, year) + 1) {//进位 
			day = 1;
			month++;
		}
		if (month == 13) {//进位  
			month = 1;
			year++;
		}
	}
	return *this;
}
//加n天，考虑进位月和年，考虑闰年
int main()
{

	char type[110];

	int day, mon, year;

	int addday, addmon, addyear;
	
	while (cin >> type)

	{

		if (strcmp(type, "Date") == 0)

		{

			cin >> day >> mon >> year;

			Date mydate(day, mon, year);

			cin >> addday >> addmon >> addyear;

			mydate.add_day(addday).add_month(addmon).add_year(addyear);

			cout << mydate.get_day() << " " << mydate.get_month() << " " << mydate.get_year() << endl;

		}

		else if (strcmp(type, "defaultDate") == 0)

		{

			cout << Date::get_default_day() << " " << Date::get_default_month() << " " << Date::get_default_year() << endl;

		}

		else if (strcmp(type, "setdefaultDate") == 0)

		{

			cin >> day >> mon >> year;

			Date::set_default(day, mon, year);

			cout << Date::get_default_day() << " " << Date::get_default_month() << " " << Date::get_default_year() << endl;

		}

	}

	return 0;

}
int isLeapYear(int year)
{
	return ((year % 4 == 0) && (year % 100 != 0) || year % 400 == 0);
}
int yeard(int y)
{
	if (isLeapYear(y)) {
		return 366;
	}
	else {
		return 365;
	}
}
int monthx(int m1, int y1)
{
	int num;
	switch (m1) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		num = 31;
		break;
	case 2:
		num = yeard(y1) - 337;
		break;
	default:
		num = 30;
		break;
	}
	return num;
}