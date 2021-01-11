#define _CRT_SECURE_NO_WARNINGS //put in first line
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class String
{
private:
	char * s;
public:
	String();
	
	String(const char *);
	String(const String &);
	~String();
	String & operator=(const char *);
	String & operator=(const String &);
	String operator+(const char *);
	String operator+(const String &);
	String & operator+=(const char *);
	String & operator+=(const String &);
	friend istream & operator>>(istream &, String &);
	friend ostream & operator<<(ostream &, const String &);
	friend bool operator==(const String &, const char *);
	friend bool operator==(const String &, const String &);
	friend bool operator!=(const String &, const char *);
	friend bool operator!=(const String &, const String &);
};



int main()
{
	String s;
	s += "hello";
	cout << s << endl;
	String s1("String1");
	String s2("copy of ");
	s2 += "String1";
	cout << s1 << "\n" << s2 << endl;
	String s3;
	cin >> s3;
	cout << s3 << endl;
	String s4("String4"), s5(s4);
	cout << (s5 == s4) << endl;
	cout << (s5 != s4) << endl;
	String s6("End of "), s7("my string.");
	s6 += s7;
	cout << s6 << endl;
	return 0;
}

String::String()
{
	s = new char[2000];
}

String::String(const char *x)
{
	s = new char[strlen(x) + 1];
	strcpy(s, x);
}

String::String(const String &x)
{
	s = new char[strlen(x.s) + 1];
	strcpy(s, x.s);
}

String::~String()
{
	delete[]s;
}

String & String::operator=(const char *x)
{
	// TODO: 在此处插入 return 语句
	//s = new char[strlen(x) + 1];
	//strcpy(s, x);
	//return *this;
	return operator=(String(x));
}

String & String::operator=(const String &x)
{
	// TODO: 在此处插入 return 语句
	      s = new char[strlen(x.s) + 1];
	    strcpy(s, x.s);
	    return *this;
}

String String::operator+(const char *x)
{
	return String(s)+String(x);
}

String String::operator+(const String &x)
{
	return String(s)+x;
}

String & String::operator+=(const char *x)
{
	// TODO: 在此处插入 return 语句
	return operator+=(String(x));
}

String & String::operator+=(const String &x)
{
	// TODO: 在此处插入 return 语句
	char*tmp = new char[strlen(s) + strlen(x.s) + 1];
	tmp = this->s;
	strcat(tmp, x.s);
	this->s = tmp;
	return *this;
}

istream & operator>>(istream &is, String &x)
{
	// TODO: 在此处插入 return 语句
	char tmp[2000];
	is >> tmp;
	if (is)
	{
		strcpy(x.s, tmp);
	}
	return is;
}

ostream & operator<<(ostream &os, const String &x)
{
	// TODO: 在此处插入 return 语句
	os << x.s;
	return os;
}

bool operator==(const String &x, const char *y)
{
	return strcmp(x.s, y) == 0;
}

bool operator==(const String &x, const String &y)
{
	return strcmp(x.s, y.s) == 0;
}

bool operator!=(const String &x, const char *y)
{
	return strcmp(x.s, y) != 0;
}

bool operator!=(const String &x, const String &y)
{
	return strcmp(x.s, y.s) != 0;
}
