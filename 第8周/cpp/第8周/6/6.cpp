#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
	Car(string con_carname, int con_seats)               //定义带有两个参数的构造函数
	{
		cout << "Calling Car constructor, set carname,seats!" << endl;
		m_strCarName = con_carname;                      //对m_strCarName属性赋值
		m_nSeats = con_seats;                             //对m_nSeats属性赋值
	}
	Car(string con_carname)                               //定义带有一个参数的构造函数
	{
		cout << "Calling Car constructor, set carname!" << endl;
		m_strCarName = con_carname;
	}
	void disp_memmsg()                                     //显示成员值的函数
	{
		cout << "carname: " << m_strCarName << ","
			<< "seats = " << m_nSeats << endl;
	}
private:
	string m_strCarName;
	int m_nSeats;
};
int main()
{
	Car mycar("my new car", 4);                       //调用带两个参数的构造函数创建对象
	Car tomcar("tom's car");                           //调用带一个参数的构造函数创建对象
	mycar.disp_memmsg();
	tomcar.disp_memmsg();

	system("pause");
	return 0;
}

