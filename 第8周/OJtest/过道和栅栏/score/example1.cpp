#include<iostream>
#include<string>
using namespace std;
class Score
{

private:

	string name;//记录学生姓名
	double s[4];//存储4次成绩，s[0]和s[1]存储2次随堂考试，s[2]存储期中考试，s[3]存储期末考试
	double total;//记录总评成绩
	char grade;  //记录对应的等级
public:
	void Input();
	void Evalauate();
	void Output();
};
void Score::Input()
{
	
	cin >> name;
	cin >> s[0] >> s[1];
	cin >> s[2] >> s[3];
	
		

}
void Score::Evalauate()
{
	
	if ((s[0] >= 0 && s[0] <= 50) && (s[1] >= 0 && s[1] <= 50) && (s[2] >= 0 && s[2] <= 100) && (s[3] >= 0 && s[3] <= 100))
	{ 
	total = (s[0] + s[1])*0.25 + s[2] * 0.25 + s[3] * 0.5;
	if (total <= 100 && total >= 90) grade = 'A';
	else if (total <= 89 && total >= 80) grade = 'B';
	else if (total <= 79 && total >= 70) grade = 'C';
	else if (total <= 69 && total >= 60) grade = 'D';
	else if (total <  60 && total >=  0) grade = 'E';
	}
	else grade = -1;

}
void Score::Output()
{
	if (-1 == grade) cout << "error";
	else cout << "name: " << name << ", " <<"total: "<< total << ", " << "grade: " << grade;
}

int main()
{
    Score *s1=new Score;
    s1->Input();
    s1->Evalauate();
    s1->Output();
    return 0;
}