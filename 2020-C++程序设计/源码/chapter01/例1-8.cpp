#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1 = "hello C++";
	string s2 = "chuan zhi bo ke!";
	cout << "before swap: " << endl;
	cout << "s1: " << s1 << endl << "s2: " << s2 << endl;
	s1.swap(s2);
	cout << "after swap: " << endl;
	cout << "s1: " << s1 << endl << "s2: " << s2 << endl;
	system("pause");
	return 0;
}
