#include <iostream>
#include <string>
using namespace std;

class Student                                              //定义Student类
{
public:
	Student(string con_name, int con_id);
	~Student();
	string get_stdname() const;                         //用const声明常成员函数
	void print_stdname();
private:
	string m_strName;//const string m_strName;
	int m_nID;
};
//定义Student的构造函数
Student::Student(string con_name, int con_id) :m_strName(con_name)
{
	m_nID = con_id;
}
Student::~Student()
{
}
string Student::get_stdname() const                  //定义常成员函数，获取学生姓名
{
	//m_strName = "Paul";                               //错误，常成员函数不可以修改成员的值
	return m_strName;
}
void Student::print_stdname()                         //普通成员函数，显示学生姓名
{
	//m_strName = "Paul";                              //正确， 普通成员函数可以修改成员的值
	cout << "std's name:" << m_strName << endl;
}
int main()
{
	Student std_tom("Tom", 20);
	std_tom.print_stdname();                         //调用普通成员函数
	cout << std_tom.get_stdname() << endl;        //调用常成员函数
	system("pause");
	return 0;
}
