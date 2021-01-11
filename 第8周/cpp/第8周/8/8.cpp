#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
	Car(string con_carname)                     //定义带参数的构造函数
	{
		m_strCarName = con_carname;
	}
private:
	string m_strCarName;
};

int main()
{
	Car mycar;                                   //应调用无参数的构造函数创建对象
	return 0;
}
