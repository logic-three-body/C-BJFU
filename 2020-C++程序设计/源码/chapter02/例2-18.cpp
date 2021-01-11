#include <iostream>
#include <string>
using namespace std;

class Student                                         //定义Student类
{
public:
	Student(string con_name, int con_id);
	~Student();
	string get_stdname();
	//静态成员函数get_totalnum()，访问静态数据成员
	static int get_totalnum();
	//静态成员函数get_totalnum()，为了访问非静态数据成员，带有对象引用参数
	static int get_totalnum(Student &stdref);

private:
	static int s_nTotalNum;                            //静态数据成员s_nTotalNum
	string m_strName;
	int m_nID;
};
//定义Student构造函数，每创建一个对象，记录学生总人数的s_nTotalNum自增1
Student::Student(string con_name, int con_id) :m_strName(con_name)
{
	s_nTotalNum++;
	m_nID = con_id;
}
//定义析构函数，每析构一个对象，s_nTotalNum减1
Student::~Student()
{
	s_nTotalNum--;
	cout << "destructor, totalnum = " << s_nTotalNum << endl;
	if (s_nTotalNum == 0)
		system("pause");
}

string Student::get_stdname()                      //定义获取学生姓名的函数
{
	return m_strName;
}
//定义静态成员函数，获取s_nTotalNum值并显示了某个学生的姓名
int Student::get_totalnum(Student &stdref)
{
	cout << stdref.m_strName << " entered the school!" << endl;
	return s_nTotalNum;
}
////定义静态成员函数，获取静态数据成员s_nTotalNum的值
int Student::get_totalnum()
{
	return s_nTotalNum;
}

int Student::s_nTotalNum = 0;                     //初始化静态数据成员s_nTotalNum

int main()
{
	cout << "access to static func \"get_totalnum()\": totalnum = "
		<< Student::get_totalnum() << endl;     //通过类名访问静态成员函数

	Student std_tom("Tom", 20);                   //定义类对象std_tom

	cout << std_tom.get_stdname() << ", totalnum = "
		<< std_tom.get_totalnum(std_tom) << endl;//通过对象访问静态成员函数

	return 0;
}
