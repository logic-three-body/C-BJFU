#include<iostream>
using namespace std;
class Rectangle
{

private:

	double length; //长

	double width; //宽
public:

	Rectangle(double Length = 10., double Width = 5.);

	double Area(); //获取面积

	double Perimeter();//获取周长

};
double Rectangle::Area()
{
	return length * width * 240;
}
double Rectangle::Perimeter()
{
	return (length + width) * 2 * 50 ;
}
Rectangle::Rectangle(double Length , double Width)
{
	length = Length;
	width = Width;
}
int main()
{
	double x, y;
	cin >> x >> y;
	Rectangle field(x + 3, y + 3);
	cout << field.Perimeter() << endl;
	cout << field.Area()-x*y*240 << endl;
	
	return 0;
}