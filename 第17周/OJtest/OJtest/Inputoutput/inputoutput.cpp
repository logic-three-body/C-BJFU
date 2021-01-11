#include<iostream>
#include<string>
using namespace std;
class PersonInfo
{
	
public:
	PersonInfo(const string&,const int&);
	~PersonInfo();
	string Name();
	int Age();

private:
	std::string per_name;
	int per_year;


};

PersonInfo::PersonInfo(const string&x, const int&y):per_name(x),per_year(y)
{
}

PersonInfo::~PersonInfo()
{
}

string PersonInfo::Name()
{
	return per_name;
}

int PersonInfo::Age()
{
	return per_year;
}

int main()
{
	string    name;
	int    year;
	cin >> name >> year;
	PersonInfo info(name, year);
	cout << "I am " << info.Name() << ", " << info.Age() << " years old.\n";
	return 0;
}