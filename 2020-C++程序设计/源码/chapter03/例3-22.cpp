#include<iostream>  
using namespace std;
const double PI = 3.14159;
class Shapes                                      //定义表示形状的抽象类  
{
public:
	Shapes(int x, int y = 0);
	virtual ~Shapes();
	virtual void disp() = 0;                   //声明纯虚函数，显示形状面积  
protected:
	int m_nX, m_nY;
};
Shapes::Shapes(int x, int y)                  //定义Shapes类的构造函数
{
	m_nX = x;
	m_nY = y;
}
Shapes::~Shapes()                               //定义Shapes类的析构函数
{
	cout << "Shapes destructor!" << endl;
}
class Square :public Shapes                    //矩形派生类
{
public:
	Square(int square_x, int square_y);
	~Square();
	void disp();
};
//矩形类Square构造函数的实现
Square::Square(int square_x, int square_y) :Shapes(square_x, square_y)
{
}
Square::~Square()                               //矩形类Square析构函数的实现
{
	cout << "Square destructor!" << endl;
}
void Square::disp()                             //对基类纯虚函数的实现
{
	cout << "square area:" << m_nX * m_nY << endl;
}
class Circle :public Shapes                    //圆形派生类
{
public:
	Circle(int radius);
	~Circle();
	void disp();                                //与基类纯虚函数同名的函数
};
Circle::Circle(int radius) :Shapes(radius) //派生类Circle构造函数的实现
{
}
Circle::~Circle()                              //派生类Circle析构函数的实现
{
	cout << "Circle destructor!" << endl;
}
void Circle::disp()                            //对基类纯虚函数的实现
{
	cout << "circle area:" << PI * m_nX * m_nX << endl;
}
int main()
{
	Shapes *ptr[2];                            //定义基类指针数组  

	ptr[0] = new Square(10, 5);             //通过new创建派生类Square对象
	ptr[0]->disp();
	ptr[1] = new Circle(10);                 //通过new创建派生类Circle对象
	ptr[1]->disp();
	for (int i = 0; i < 2; i++)
		delete ptr[i];
	system("pause");
	return 0;
}
