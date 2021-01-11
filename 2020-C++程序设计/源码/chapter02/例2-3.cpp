#include <iostream>
#include <string>
using namespace std;

class Car                                              //定义汽车类
{
public:
	void set_carname(string newname)             //设置汽车名称的成员函数
	{
		m_strCarName = newname;
	}
	string get_carname()                            //获取汽车名称的成员函数
	{
		return m_strCarName;
	}
	void display_welcomemsg()                      //显示欢迎信息的成员函数
	{
		cout << "Welcome to the car world  for " << m_strCarName << "!" << endl;
	}
private:
	string m_strCarName;
};

int main()
{
	string new_carname;                             //定义变量用于保存用户输入的汽车名称
	Car mycar;

	cout << "enter the car name : ";
	getline(cin, new_carname);                    //使用getline()函数读取一个字符串
	mycar.set_carname(new_carname);              //调用函数设置汽车名称
	mycar.display_welcomemsg();                   //显示欢迎信息

	system("pause");
	return 0;
}
