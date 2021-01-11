#include <iostream>
#include <cstring>
using namespace std;
class Car                                                  //定义类Car
{
public:
	Car(char *con_pcarname, int con_seats);         //声明带参数的构造函数
	Car(Car &con_refcar);                              //声明拷贝构造函数
	~Car();                                               //声明析构函数

private:
	char *m_pCarName;                                   //指针成员，指向存有汽车名称的空间
	int m_nSeats;
};

Car::Car(char *con_pcarname, int con_seats)         //构造函数定义
{
	int len = strlen(con_pcarname) + 1;
	m_pCarName = new char[len];                        //开辟空间，m_pCarName记录首地址

	//向m_pCarName指向的空间中复制汽车名称
	strcpy_s(m_pCarName, len, con_pcarname);
	m_nSeats = con_seats;
}
Car::Car(Car &con_refcar)                          //定义拷贝构造函数
{
	cout << "calling copy constructor!" << endl;
	int len = strlen(con_refcar.m_pCarName) + 1;
	m_pCarName = new char[len];                  //m_pCarName指向new开辟的空间
	strcpy_s(m_pCarName, len, con_refcar.m_pCarName);
	m_nSeats = con_refcar.m_nSeats;
	cout << "end of copy constructor!" << endl;
}
Car::~Car()                                           //定义析构函数
{
	static int i = 0;
	cout << "destructor is called!" << endl;
	delete[] m_pCarName;                           //释放m_pCarName指向的空间
	if (i == 1)
		system("pause");
	i++;
}

int main()
{
	Car mynewcar("my new car", 4);             //调用带参数的构造函数定义类对象
	Car myseccar(mynewcar);                     //调用拷贝构造函数定义类对象
	return 0;
}
