#include<iostream>
#include<string>
using namespace std;
class Complex

{

private:

	double x;//real

	double y;//imag

public:

	Complex(double x = 0.0, double y = 0.0):x(x),y(y) {};

	Complex & operator+=(const Complex &);

	Complex & operator-=(const Complex &);

	Complex & operator*=(const Complex &);

	Complex & operator/=(const Complex &);

	friend Complex operator+(const Complex &, const Complex &);

	friend Complex operator-(const Complex &, const Complex &);

	friend Complex operator*(const Complex &, const Complex &);

	friend Complex operator/(const Complex &, const Complex &);

	friend bool operator==(const Complex &, const Complex &);

	friend bool operator!=(const Complex &, const Complex &);

	friend ostream & operator<<(ostream &, const Complex &);

	friend istream & operator>>(istream &, Complex &);

};

Complex operator+(const Complex &a, const Complex &b)
{
	return Complex((a.x+b.x),(a.y+b.y));
}

Complex operator-(const Complex &a, const Complex &b)
{
	return Complex((a.x - b.x), (a.y - b.y));
}

Complex operator*(const Complex &a, const Complex &b)
{
	return Complex((a.x*b.x-a.y*b.y),(a.x*b.y+a.y*b.x));
}

Complex operator/(const Complex &a, const Complex &b)
{
	return Complex(((a.x*b.x+a.y*b.y)/(b.x*b.x+b.y*b.y)),((a.y*b.x-a.x*b.y)/(b.x*b.x+b.y*b.y)));
}

bool operator==(const Complex &a, const Complex &b)
{
	return (a.x==b.x&&a.y==b.y);
}

bool operator!=(const Complex &a, const Complex &b)
{
	return !(a.x == b.x&&a.y == b.y);
}

ostream & operator<<(ostream &os, const Complex &st)
{
	// TODO: 在此处插入 return 语句
	os << st.x << " + " << st.y<<"i";
	return os;
}

istream & operator>>(istream &is, Complex &st)
{
	// TODO: 在此处插入 return 语句
	is >> st.x >> st.y;
	return is;
}

//Complex & Complex::operator+=(const Complex &B)
//{
//	// TODO: 在此处插入 return 语句
//	Complex A;
//	A.x = x;
//	A.y = y;
//	A.x += B.x;
//	A.y += B.y;
//	return A;
//
//}

Complex & Complex::operator+=(const Complex &B)
{
	// TODO: 在此处插入 return 语句

	x += B.x;
	y += B.y;
	return *this;

}

Complex & Complex::operator-=(const Complex &B)
{
	// TODO: 在此处插入 return 语句
	x -= B.x;
	y -= B.y;
	return *this;
}

Complex & Complex::operator*=(const Complex &B)
{
	// TODO: 在此处插入 return 语句
	Complex t;
	t.x = x;
	x = (x*B.x - y * B.y);
	y = (t.x*B.y + y * B.x);
	return *this;
}

Complex & Complex::operator/=(const Complex &B)
{
	// TODO: 在此处插入 return 语句
	Complex t;
	t.x = x;
	x = (x*B.x + y * B.y) / (B.x*B.x + B.y*B.y) ;
	y = (y*B.x -t.x * B.y) / (B.x*B.x + B.y*B.y);
	return *this;
}


int main()

{

	Complex c1, c2;

	cin >> c1 >> c2;

	cout << "c1 = " << c1 << "\n" << "c2 = " << c2 << endl;


	cout << "c1+c2 = " << c1 + c2 << endl;

	cout << "c1-c2 = " << c1 - c2 << endl;

	cout << "c1*c2 = " << c1 * c2 << endl;

	cout << "c1/c2 = " << c1 / c2 << endl;

	cout << (c1 += c2) << endl;

	cout << (c1 -= c2) << endl;

	cout << (c1 *= c2) << endl;

	cout << (c1 /= c2) << endl;

	cout << (c1 == c2) << " " << (c1 != c2) << endl;

	return 0;

}