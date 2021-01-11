#include <iostream>
using namespace std;
class Student
{
private:
	int id;
	double score;
public:
	friend ostream& operator<< (ostream& os, const Student& st);
	friend istream& operator>> (istream& is, Student& st);
	//重载关系运算符
	friend bool operator== (const Student& st1, const Student& st2);
	friend bool operator!= (const Student& st1, const Student& st2);
	friend bool operator> (const Student& st1, const Student& st2);
	friend bool operator< (const Student& st1, const Student& st2);
};

ostream& operator<< (ostream& os, const Student& st)
{
	os << "id:" << st.id << ", score:" << st.score;
	return os;
}

istream& operator>> (istream& is, Student& st)
{
	is >> st.id >> st.score;
	return is;
}

bool operator== (const Student& st1, const Student& st2)
{
	return st1.score == st2.score; //重载==运算符
}
bool operator!= (const Student& st1, const Student& st2)
{
	return !(st1.score == st2.score); //重载!=运算符
}

bool operator> (const Student& st1, const Student& st2)
{
	return st1.score > st2.score; //重载>运算符
}

bool operator< (const Student& st1, const Student& st2)
{
	return st1.score < st2.score; //重载<运算符
}

int main()
{
	Student st1, st2;
	cout << "请输入两名学生的id编号和成绩：" << endl;
	cin >> st1 >> st2;
	cout << "比较两名学生的成绩：" << endl;
	if (st1 > st2)
		cout << "第一个学生成绩较高：" << st1 << endl;
	else if (st1 < st2)
		cout << "第二个学生成绩较高：" << st2 << endl;
	else
		cout << "两名学生成绩相同：" << st2 << endl;

	system("pause");
	return 0;
}
