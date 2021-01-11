#pragma comment(lib, "HITP450.lib")
#include<iostream>
#include<cmath>
using namespace std;
int gcd(int a, int b);//����������
class Rational
{
private:
	int z;    //����
	int m;    //��ĸ
public:
	Rational(int a = 0, int b = 1);  //��������������������Ĭ��Ϊ0����ĸĬ��Ϊ1
	Rational& yuefen(); //Լ�ֺ����Է�������
	friend Rational operator+(const Rational &r1, const Rational &r2);
	friend Rational operator-(const Rational &r1, const Rational &r2);
	friend Rational operator*(const Rational &r1, const Rational &r2);
	friend Rational operator/(const Rational &r1, const Rational &r2);
	//Rational & operator+=(const Rational &r);
	//Rational & operator-=(const Rational &r);
	//Rational & operator*=(const Rational &r);
	//Rational & operator/=(const Rational &r);

	//friend bool operator==(const Rational &, const Rational &);//�ж������������Ƿ����

	//friend bool operator!=(const Rational &, const Rational &);//�ж������������Ƿ񲻵�

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

Rational & Rational::yuefen()
{
	// TODO: �ڴ˴����� return ���
	int tmp;
	tmp = gcd(this->z, this->m);
	this->z /= tmp;
	this->m /= tmp;


	//ͬ��
	if (this->z < 0 && this->m < 0)
	{
		this->z = abs(this->z);
	}

	//���
	else if ((this->z > 0 && this->m < 0))
	{
		this->z = -this->z;
		this->m = -this->m;
	}


	return *this;
}

Rational::Rational(int a, int b) :z(a), m(b)
{
	yuefen();
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

ostream & operator<<(ostream &os, const Rational &ra)
{
	// TODO: �ڴ˴����� return ���
	os << ra.z << "/" << ra.m;
	return os;
}

istream & operator>>(istream &is, Rational &ra)
{
	// TODO: �ڴ˴����� return ���
	is >> ra.z >> ra.m;
	return is;
}

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
		//cout << (r1 == r2) << " " << (r1 != r2) << endl;
		//cout << (r1 += r2) << endl;
		//cout << (r1 -= r2) << endl;
		//cout << (r1 *= r2) << endl;
		//cout << (r1 /= r2) << endl;
	}

	return 0;
}