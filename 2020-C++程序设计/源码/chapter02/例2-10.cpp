#include <iostream>
#include <cstring>                                     //strcpy_s()函数声明所在的头文件
using namespace std;

class Car                                               //定义类
{
public:
	Car();                                             //无参构造函数的声明
	Car(char *con_pcarname, int con_seats);     //带参构造函数的声明
	~Car();                                            //析构函数的声明
	char *get_carname();
	int get_seats();
private:
	char *m_pCarName;
	int m_nSeats;
};
Car::Car()                                           //定义无参的构造函数
{
	cout << "Car constructor!" << endl;
	m_pCarName = nullptr;                        //设置指针成员的初值为nullptr，值为0
	m_nSeats = 4;
}
Car::Car(char *con_pcarname, int con_seats)  //定义带参数的构造函数
{
	int len = strlen(con_pcarname) + 1;

	cout << "Car constructor with param,car name:" << con_pcarname << endl;
	m_pCarName = new char[len];                //数据成员m_pCarName指向新开辟的空间
	strcpy_s(m_pCarName, len, con_pcarname); //将汽车名车存入m_pCarName指向的空间
	m_nSeats = con_seats;
}
Car::~Car()                                        //定义析构函数
{
	static int i = 0;
	cout << "Car destructor,car name:" << m_pCarName << endl;
	if (m_pCarName)
		delete[] m_pCarName;                    //释放m_pCarName指向的空间
	if (i == 1)
		system("pause");
	i++;
}
char *Car::get_carname()                        //获取m_pCarName属性值
{
	return m_pCarName;
}
int Car::get_seats()                             //获取m_nSeats属性值
{
	return m_nSeats;
}
int main()
{
	Car mynewcar("my car", 4);             //创建对象
	Car tomcar("tom car", 7);              //创建对象

	cout << "my car name : " << mynewcar.get_carname() << endl;
	cout << "tom car name: " << tomcar.get_carname() << endl;

	return 0;
}
