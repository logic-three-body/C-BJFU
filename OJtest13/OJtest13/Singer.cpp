#include<iostream>
#include<string>
using namespace std;
class Singer
{
public:
	Singer();
	~Singer();
	string getName();
	friend ostream&operator<<(ostream &os, const Singer &a);//overloading cout
	friend istream&operator>>(istream &is,Singer &a);//overloading cin
	friend bool operator== (const Singer& st1, const Singer& st2);
	friend bool operator> (const Singer& st1, const Singer& st2);
private:
	string name;
	string	sex;
	int age;
	double score;
};



Singer::Singer():name("Unknown"),sex("Unknown"),age(0),score(0.0)
{
}

Singer::~Singer()
{
}

string Singer::getName()
{
	return name;
}


ostream & operator<<(ostream & os, const Singer & a)
{
	// TODO: 在此处插入 return 语句
	os << a.name << " " << a.sex << " " << a.age << " " << a.score;
	return os;
}

istream & operator>>(istream & is, Singer & a)
{
	// TODO: 在此处插入 return 语句
	is >> a.name >> a.sex >> a.age >> a.score;
	return is;
}

bool operator==(const Singer & st1, const Singer & st2)
{
	return (st1.score==st2.score);
}

bool operator>(const Singer & st1, const Singer & st2)
{
	return (st1.score > st2.score);
}

int main()

{

	Singer s1, s2;

	cin >> s1 >> s2;

	cout << s1 << "\n" << s2 << endl;

	if (s1 > s2)

		cout << s1.getName() << "'s score is higher than " << s2.getName() << "'s.\n";

	else if (s1 == s2)

		cout << s1.getName() << "'s score is equal to " << s2.getName() << "'s.\n";

	else

		cout << s1.getName() << "'s score is lower than " << s2.getName() << "'s.\n";

	return 0;
}

