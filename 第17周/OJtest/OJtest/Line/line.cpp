#include<iostream>
#include<cmath>
using namespace std;

template<typename T>
class Point2
{
private:
	T x, y;
public:
	Point2(T a, T b) :x(a), y(b) {};
	T getX() { return x; };
	T getY() { return y; };
};

template<typename T>
class Line2
{

public:
	Line2(Point2<T>a,	Point2<T>b);
	
	T Length() { return length; };

private:
	T length;

};
template<typename T>
Line2<T>::Line2(Point2<T> a, Point2<T> b)
{
	length = sqrt(pow(a.getX()-b.getX(),2)+pow(a.getY()-b.getY(),2));
	//return length;
}

int main()
{
	Point2<double> pt1(1.0, 1.0);
	Point2<double> pt2(3.0, 4.0);
	Line2<double> line(pt1, pt2);
	cout << line.Length() << endl;

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	Line2<int> nLine(Point2<int>(x1, y1), Point2<int>(x2, y2));
	cout << nLine.Length() << endl;

	return 0;
}