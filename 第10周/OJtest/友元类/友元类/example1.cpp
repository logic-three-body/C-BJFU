#include<iostream>
#include<string>
using namespace std;
class Subject    //选课类
{
private:
	double score[3];                //3门课成绩
	const int SMath=4, SEng=2, SCpp=2;    //3门课的学分，分别为4、2、2
public:
	Subject(int math = 0, int eng = 0, int cpp = 0);
	void Input();            //输入3门课的成绩
	friend class Student;    //友元类
};
Subject::Subject(int math , int eng , int cpp)
{

}

class Student
{
private:
	string ID;        //学号
	string name;       //姓名
	double GPA;        //平均学分积=（成绩1x学分1+成绩2x学分2+成绩3x学分3）/（学分1+学分2+学分3）
public:
	Student(string id = "00000", string na = "Noname");
	void CalculateGPA(const Subject &sub);    //计算平均学分积
	void Input();                            //输入学号和姓名
	void Show(const Subject &sub)const;        //输出所有信息
};
Student::Student(string id, string na)
{

}


void Student::Input()
{
	
	cin >> ID >> name;
}
void Subject::Input()
{
	cin >> score[0] >> score[1] >> score[2];
}

void Student::CalculateGPA(const Subject &sub)
{
	GPA = (sub.score[0] * 4 + sub.score[1] * 2 + sub.score[2] * 2)/(sub.SCpp+sub.SEng+sub.SMath);
}
void Student::Show(const Subject &sub)const
{
	cout << "ID: " << ID << ", " << "Name: " << name << endl;
	cout << "Math Eng Cpp" << endl;
	cout << sub.score[0] << " " << sub.score[1] << " " << sub.score[2]<<<< endl;
	cout << "GPA: " << GPA<<endl;
}
int main()
{
	int n;        //学生人数
	cin >> n;
	Student *stu = new Student[n];
	Subject *sub = new Subject[n];
	for (int i = 0; i < n; i++)
	{
		stu[i].Input();
		sub[i].Input();
	}
	for (int i = 0; i < n; i++)
	{
		stu[i].CalculateGPA(sub[i]);
		stu[i].Show(sub[i]);
	}
	delete[] stu;
	delete[] sub;
	return 0;
}