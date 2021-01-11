#include<iostream>
#include<list>
#include<string>

using namespace std;
struct Student
{
	int no;
	string name;
};
void Input(list<Student>&li)
{
	int n;
	cin >> n;
	while (n--)
	{
		Student stu;
		cin >> stu.no >> stu.name;
		li.push_back(stu);
	}
}

void Show(list<Student>&li)
{
	//cout << "Good job!" << endl;
	list<Student>::const_iterator it;
	for (it = li.begin(); it != li.end(); it++)
	{
		cout << it->no << ", " << it->name << endl;
	}
}

int main()
{
	std::list<Student> li;
	Input(li);
	Show(li);
	return 0;
}