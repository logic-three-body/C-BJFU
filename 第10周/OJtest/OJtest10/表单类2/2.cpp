#include<iostream>
#include<string>
using namespace std;
class Date    //日期类
{
private:
	int Date_year;    //年
	int Date_month;    //月
	int Date_day;    //日
public:
	Date(int year = 2000, int month = 1, int day = 1);
	void show();    //以“年-月-日”格式输出年月日
	~Date();
};
Date::Date(int year, int month, int day)
{
	Date_year = year;
	Date_month = month;
	Date_day = day;
}
void Date::show()
{
	cout << ", Birthday: " << Date_year << "-" << Date_month << "-" << Date_day << endl;
}
Date::~Date() {}
class Croster    //名单类
{
private:
	string name;
	Date birthday;
public:
	Croster();
	Croster(string name1, int year, int month, int day);
	Croster(string name1, Date date);
	void show();//显示姓名和出生日期
	~Croster();
};

Croster::Croster()
{
	cout << "Name: NULL, Birthday: 0-0-0" << endl;
}
Croster::Croster(string name1, int year, int month, int day)
{

	cout << "Name: " << name1 << ", Birthday: " << year << "-" << month << "-" << day << endl;

}
void Croster::show()
{
	cout << "Name: " << name;
	birthday.show();
}
Croster::~Croster()
{

}
Croster::Croster(string name1, Date date)
{

	name = name1;
	show();
	
}
int main()
{

	int option = 0;
	int year, month, day;
	string name;
	cin >> option;
	while (-1 != option)
	{
		if (0 == option) Croster();
		else if (1 == option)
		{
			cin >> name >> year >> month >> day;
			Croster(name, year, month, day);
		}
		else if (-1 == option) break;
		else if (2 == option)
		{
			cin >> name >> year >> month >> day;

			Date stu(year, month, day);
			Croster(name, stu);
			/*Croster(name, Date date)*/
		}

		cin >> option;
	}

	return 0;
}

