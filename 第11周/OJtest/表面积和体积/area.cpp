#include<iostream>
using namespace std;
const double PI = acos(-1.0);
class Shape {

public:

	Shape() {}

	virtual double area() = 0;

	virtual void input() = 0;

	virtual double volume() = 0;

	virtual ~Shape() {}

};

class Cuboid :public Shape
{
public:
	void input();
	double area();
	double volume();
private:
	int a, b, c;

};

void Cuboid::input()
{
	cin >> a >> b >> c;
}

double Cuboid::area()
{
	return 2*(a*b+a*c+b*c);
}

double Cuboid::volume()
{
	return a*b*c;
}

class Cylinder :public Shape
{
private:
	double a, b;
public:
	void input();
	double area();
	double volume();
};
void Cylinder::input()
{
	cin >> a >> b ;
}

double Cylinder::area()
{
	return (2*PI*a*a+2*PI*a*b);
}

double Cylinder::volume()
{
	return (PI*a*a*b);
}

class Ball :public Shape
{
private:
	double a;
public:
	void input();
	double area();
	double volume();
};

void Ball::input()
{
	cin >> a;
}

double Ball::area()
{
	return 4.0*PI*a*a;
}

double Ball::volume()
{
	return 4.0/3.0*PI*a*a*a;
}


void work(Shape *s) {

	s->input();

	cout << s->area() << " " << s->volume() << endl;

	delete s;

}


int main() {

	char c;

	while (cin >> c) {

		switch (c) {

		case 'y':

			work(new Cylinder());

			break;

		case 'c':

			work(new Cuboid());

			break;

		case 'q':

			work(new Ball());

			break;

		default:

			break;

		}

	}

	return 0;

}