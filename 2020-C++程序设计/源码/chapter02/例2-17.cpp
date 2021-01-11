#include <iostream>
using namespace std;

class Circle                                         //定义类Circle
{
public:
	Circle(double con_radius);                    //声明构造函数
	double circumference();                       //声明求圆周长的函数
private:
	double m_fRadius;                              //数据成员，记录圆的半径
	const double PI;                                //常数据成员，描述圆周率
};
//定义构造函数，常数据成员通过初始化表初始化
Circle::Circle(double con_radius) :PI(3.14)
{
	m_fRadius = con_radius;
}
double Circle::circumference()
{
	return 2 * PI * m_fRadius;
}

int main()
{
	Circle c1(2);                                   //定义Circle对象c1
	cout << "circumference:" << c1.circumference() << endl;
	system("pause");
	return 0;
}
