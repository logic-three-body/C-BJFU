#include <iostream>
#include <sstream>
#include <string>
#include<cstdlib>
using namespace std;

int main()
{
	stringstream ostr("ccc");
	ostr.put('d');
	ostr.put('e');
	ostr << "fg";
	string gstr = ostr.str();
	cout << gstr << endl;

	char a,b;
	ostr >> a;
	cout << a << endl;
	ostr >> b;
	cout << b << endl;
	system("pause");
}