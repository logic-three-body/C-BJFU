#include <iostream>
#include <cstring>
using namespace std;

class Date                                               //定义日期类
{
public:
	Date(int y, int m, int d);                       //声明带参数的构造函数
	void show();
private:
	int m_nYear, m_nMonth, m_nDay;
};
Date::Date(int y, int m, int d)                   //定义Date类的构造函数
{
	cout << "Date constructor!" << endl;
	m_nYear = y;
	m_nMonth = m;
	m_nDay = d;
}
void Date::show()                                   //定义成员函数show()，显示日期
{
	cout << m_nYear << "-" << m_nMonth << "-" << m_nDay << endl;
}
class Student                                        //定义学生类
{
public:
	//声明带参数的构造函数，con_name表示学生姓名，con_id表示学生id，y、m、d表示日期信息
	Student(char *con_name, int con_id, int y, int m, int d);
	void disp_msg();
private:
	Date m_iBirthday;                                //Date类型的数据成员
	char m_gName[20];
	int m_nID;
};
//定义Student类带参数的构造函数，参数y、m、d用于对Date类对象m_iBirthday初始化
Student::Student(char *con_name, int con_id,
	int y, int m, int d) :m_iBirthday(y, m, d)
{
	cout << "Student constructor!" << endl;
	strcpy_s(m_gName, strlen(con_name) + 1, con_name);
	m_nID = con_id;
}
void Student::disp_msg()                          //定义成员函数disp_msg()，显示学生信息
{
	cout << "std name:" << m_gName << ", id = " << m_nID << ", birthday:";
	m_iBirthday.show();
}
int main()
{
	Student student("xiaoming", 1, 1998, 10, 25);  //调用带参数的构造函数定义类对象
	student.disp_msg();
	system("pause");
	return 0;
}
