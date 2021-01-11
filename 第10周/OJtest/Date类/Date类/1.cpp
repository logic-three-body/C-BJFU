#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int isLeapYear(int year); //�����ж�
int yeard(int y);//���ظ�������� 
int monthx(int m1, int y1);//���ظ��µ����� 
class Date
{
public:

	Date(int d = 0, int m = 0, int y = 0, int d1 = 1, int m1 = 1, int y1 = 1901); //���캯�� //��ʼ��

	int get_day() const; // ����day

	int get_month() const; //����month

	int get_year() const; // ����year

	static void set_default(int, int, int); //����default_date

	static int get_default_day(); //����ȱʡday

	static int get_default_month(); //����ȱʡmonth

	static int get_default_year(); //����ȱʡyear

	Date & add_year(int n); //��n��

	Date & add_month(int n); //��n�£����ǳ���12��

	Date & add_day(int n); //��n�죬���ǽ�λ�º��꣬��������

private:

	int day, month, year;

	static Date default_date; //��ʼ��Ϊ 1901��1��1��

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
void Date::set_default(int x, int y, int z)//�޸�Ĭ��ֵ
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
Date & Date::add_year(int n)//��n��
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
		if (month == 13) {  //����һ���ж�
			month = 1;
			year++;
		}
	}
	return *this;
}
Date & Date::add_day(int n)
{
	int remain = n;//��ʣ������
	 //�������� 
	while (remain > 0) {
		day++;
		remain--;
		if (day == monthx(month, year) + 1) {//��λ 
			day = 1;
			month++;
		}
		if (month == 13) {//��λ  
			month = 1;
			year++;
		}
	}
	return *this;
}
//��n�죬���ǽ�λ�º��꣬��������
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