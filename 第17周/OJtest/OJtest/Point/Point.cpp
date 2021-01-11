#include<iostream>
#include<string>
#include<cmath>
using namespace std;
const double PI = acos(-1.0);
class Point
{
private:
	double x, y;
public:
	Point(double a = 0, double b = 0) :x(a), y(b) {}
	~Point() {}
	double getX() const { return x; }
	double getY() const { return y; }
	void setX(double a) { x = a; }
	void setY(double b) { y = b; }
};

class Ellipse
{
public:
	Point pAxis;
	Ellipse(double x = 0, double y = 0) :pAxis(x, y) { }
	~Ellipse() { }
	Ellipse(const Ellipse&);
	Ellipse transposition();    // 转置（交换长短半轴）
	double area();            // 面积
	double eccentricity();        // 离心率
	string position(const Point);    // 位置关系
};

Ellipse::Ellipse(const Ellipse &my_axis)
{
	pAxis.setX(my_axis.pAxis.getX());
	pAxis.setY(my_axis.pAxis.getY());
}

Ellipse Ellipse::transposition()
{
	Ellipse temp;
	temp.pAxis = pAxis;
	temp.pAxis.setX(pAxis.getY());
	temp.pAxis.setY(pAxis.getX());
	return temp;

}

double Ellipse::area()
{
	double s=pAxis.getX()*pAxis.getY()*PI;
	return s;
}

double Ellipse::eccentricity()
{
	double e = 2;
	//判断长轴短轴
	if (pAxis.getX() >= pAxis.getY())
	{
		e = sqrt(abs(pow(pAxis.getX(), 2) - pow(pAxis.getY(), 2)))/pAxis.getX();
	}
	else
	{
		e= sqrt(abs(pow(pAxis.getX(), 2) - pow(pAxis.getY(), 2))) / pAxis.getY();
	}
	

	//e = sqrt(pow(pAxis.getX(),2)-pow(pAxis.getY(),2))/pAxis.getX();
	return e;
}

string Ellipse::position(const Point apoint)
{
	string result= "no judge";
	double jud=0;
	//const long double j = 1E-20;
	//判断长短轴
	//double long_axis = (pAxis.getX() >= pAxis.getY()) ? pAxis.getX() : pAxis.getY();
	//double short_axis = (pAxis.getX() < pAxis.getY()) ? pAxis.getX() : pAxis.getY();

	//jud = pow((long_axis -apoint.getX())/ long_axis, 2)+pow((short_axis -apoint.getY())/ short_axis,2);
	jud = pow(apoint.getX(), 2)/pow(pAxis.getX(),2) + pow(apoint.getY(), 2)/pow(pAxis.getY(),2);
	if (jud==1) result = "at";
	else if (jud > 1) result = "outside";
	else result = "inside";


	return result;
}

int main()
{
	double a, b;
	while (cin >> a >> b)
	{
		Ellipse d1(a, b), d2(d1), d3 = d2.transposition();
		cout << d1.area() << endl;
		cout << d2.eccentricity() << endl;
		cin >> a >> b;
		Point p(a, b);
		cout << d3.position(p) << endl;
	}
	return 0;
}

