#include<iostream>
#include<cmath>
using namespace std;
int gcd(int a, int b);//化简有理数
class Rational
{
private:
	int z;    //分子
	int m;    //分母
public:

	Rational(int a = 0, int b = 1);  //构造有理数分数，分子默认为0，分母默认为1

	Rational& yuefen(); //约分函数对分数化简

	friend Rational operator+(const Rational &r1, const Rational &r2);

	friend Rational operator-(const Rational &r1, const Rational &r2);

	friend Rational operator*(const Rational &r1, const Rational &r2);

	friend Rational operator/(const Rational &r1, const Rational &r2);

	//Rational & operator+=(const Rational &r);

	//Rational & operator-=(const Rational &r);

	//Rational & operator*=(const Rational &r);

	//Rational & operator/=(const Rational &r);

	friend bool operator==(const Rational &, const Rational &);//判断两个有理数是否相等

	friend bool operator!=(const Rational &, const Rational &);//判断两个有理数是否不等

	friend ostream & operator<<(ostream &, const Rational &);

	friend istream & operator>>(istream &, Rational &);

};
int gcd(int a, int b)
{
	int tmp;
	tmp = a = abs(a);
	b = abs(b);
	a = a < b ? b : a;
	b = tmp < b ? tmp : b;
	if (a%b != 0)
		return gcd(a%b, b);
	else
		return b;
}
Rational operator+(const Rational & r1, const Rational & r2)
{
	Rational temp;	temp.m = r1.m*r2.m;	temp.z = r1.z*r2.m + r2.z*r1.m;	return temp;
}
Rational operator-(const Rational & r1, const Rational & r2)
{
	Rational temp;	temp.m = r1.m*r2.m;	temp.z = r1.z*r2.m - r2.z*r1.m;	return temp;
}
Rational operator*(const Rational & r1, const Rational & r2)
{
	Rational temp;	temp.m = r1.m*r2.m;	temp.z = r1.z*r2.z;	return temp;
}

Rational operator/(const Rational & r1, const Rational & r2)
{
	Rational temp;	temp.m = r1.m*r2.z;	temp.z = r1.z*r2.m;	return temp;
}

bool operator==(const Rational &r1, const Rational &r2)
{
	int tmp;
	int r1_m, r1_z, r2_m, r2_z;
	tmp = gcd(r1.z, r1.m);
	r1_z = r1.z / tmp;
	r1_m = r1.m / tmp;

	tmp = gcd(r2.z, r2.m);
	r2_z = r2.z / tmp;
	r2_m = r2.m / tmp;
	if (r1_m == r2_m && r1_z == r2_z)
		return true;
	else
		return false;
}
bool operator!=(const Rational &r1, const Rational &r2)
{
	int tmp;
	int r1_m, r1_z, r2_m, r2_z;
	tmp = gcd(r1.z, r1.m);
	r1_z = r1.z / tmp;
	r1_m = r1.m / tmp;

	tmp = gcd(r2.z, r2.m);
	r2_z = r2.z / tmp;
	r2_m = r2.m / tmp;
	if (r1_m == r2_m && r1_z == r2_z)
		return false;
	else
		return true;
}
ostream & operator<<(ostream &os, const Rational &ra)
{
	// TODO: 在此处插入 return 语句
	os << ra.z << "/" << ra.m;
	return os;
}
istream & operator>>(istream &is, Rational &ra)
{
	// TODO: 在此处插入 return 语句
	is >> ra.z >> ra.m;
	return is;
}
Rational::Rational(int a, int b) :z(a), m(b)
{
	yuefen();
}
Rational & Rational::yuefen()
{
	// TODO: 在此处插入 return 语句
	int tmp;
	tmp = gcd(z, m);
	z /= tmp;
	m /= tmp;
	//同号
	if (z < 0 && m < 0)
	{
		z = abs(z);
	}	
	else if ((z > 0 && m < 0))//异号
	{
		z = -z;
		m = -m;
	}
	return *this;
}

//Rational & Rational::operator+=(const Rational & r)
//{
//	// TODO: 在此处插入 return 语句
//	* = * + r;//运用operator+////	return *this;
//}
//
//Rational & Rational::operator-=(const Rational & r)
//{
//	// TODO: 在此处插入 return 语句
//	* = * - r;//运用operator-//	return *this;//
//}
//
//Rational & Rational::operator*=(const Rational & r)
//{
//	// TODO: 在此处插入 return 语句
//	* = * * r;//运用operator*//	return *this;//
//}
//
//Rational & Rational::operator/=(const Rational & r)
//{
//	// TODO: 在此处插入 return 语句
//	* = * / r;//运用operator///	return *this;//
//}

int main()
{
	Rational r1, r2, r3;

	while (cin >> r1 >> r2)
	{
		cout << "r1 = " << r1 << "\n" << "r2 = " << r2 << endl;
		r3 = r1 + r2;
		cout << "r1+r2 = " << r3 << endl;
		r3 = r1 - r2;
		cout << "r1-r2 = " << r3 << endl;
		r3 = r1 * r2;
		cout << "r1*r2 = " << r3 << endl;
		r3 = r1 / r2;

		cout << "r1/r2 = " << r3 << endl;
		cout << (r1 == r2) << " " << (r1 != r2) << endl;
		//cout << (r1 += r2) << endl;
		//cout << (r1 -= r2) << endl;
		//cout << (r1 *= r2) << endl;
		//cout << (r1 /= r2) << endl;
	}

	return 0;
}