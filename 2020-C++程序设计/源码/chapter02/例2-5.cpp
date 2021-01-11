#include <iostream>
#include <string>
using namespace std;

class Car                                                      //定义类
{
public:
	Car()                                                      //定义构造函数
	{
		cout << "Car constructor!" << endl;
		m_strCarName = "default name";
	}
	string get_carname()                                    //定义获取汽车名称的函数
	{
		return m_strCarName;
	}
private:
	string m_strCarName;                                     //数据成员，记录汽车名称
};

int main()
{
	Car mycar;                                                //创建对象

	cout << "car name : " << mycar.get_carname() << endl;   //显示汽车名称
	system("pause");
	return 0;
}
