#include<iostream>
#include<string>
using namespace std;
class Subject    //ѡ����
{
private:
	double score[3];                //3�ſγɼ�
	const int SMath=4, SEng=2, SCpp=2;    //3�ſε�ѧ�֣��ֱ�Ϊ4��2��2
public:
	Subject(int math = 0, int eng = 0, int cpp = 0);
	void Input();            //����3�ſεĳɼ�
	friend class Student;    //��Ԫ��
};
Subject::Subject(int math , int eng , int cpp)
{

}

class Student
{
private:
	string ID;        //ѧ��
	string name;       //����
	double GPA;        //ƽ��ѧ�ֻ�=���ɼ�1xѧ��1+�ɼ�2xѧ��2+�ɼ�3xѧ��3��/��ѧ��1+ѧ��2+ѧ��3��
public:
	Student(string id = "00000", string na = "Noname");
	void CalculateGPA(const Subject &sub);    //����ƽ��ѧ�ֻ�
	void Input();                            //����ѧ�ź�����
	void Show(const Subject &sub)const;        //���������Ϣ
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
	int n;        //ѧ������
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