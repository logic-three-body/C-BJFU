#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	Person();
	~Person();
	virtual void input();
	virtual void display();

protected:

	string nam;

};

Person::Person()
{
}

Person::~Person()
{
}

void Person::input()
{
	cin >> nam;

}

void Person::display()
{
	cout << nam << endl;

}

class Student :public Person
{
public:
	Student();
	~Student();
	 void input();
	 void display();

private:
	string num;
};

Student::Student()
{

}

Student::~Student()
{
}

void Student::input()
{
	cin >> num >> nam;
}

void Student::display()
{
	cout << num << " " << nam << endl;
}

int main()

{

	Person * p;

	p = new Person;

	p->input();

	p->display();

	delete p;

	p = new Student;

	p->input();

	p->display();

	delete p;

	return 0;

}