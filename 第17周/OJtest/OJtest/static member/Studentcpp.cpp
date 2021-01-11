#include<iostream>
#include<string>
using namespace std;
class Student
{
private:
	int age;   //年龄
	string name;  //姓名
public:
	static int count; //静态成员，表示学生人数
	Student(int a, string n);
	Student();
	~Student();
	void Print();
};

Student::Student(int a, string n):age(a),name(n)
{
}

Student::Student():name("NoName"),age(0)
{
	++count;
}

Student::~Student()
{
}

void Student::Print()
{
	cout << "Name=" << name << ", " << "age=" << age << endl;
}

int Student::count = 0;

int main()
{
	
	cout << "count=" << Student::count << endl;
	Student s1, *p = new Student(23, "ZhangHong");
	s1.Print();
	p->Print();
	delete p;
	s1.Print();
	Student Stu[4];
	cout << "count=" << Student::count << endl;
	return 0;
}
