#include<iostream>
#include<string>
using namespace std;
void Replace(string &a, const char b, const char c);
int main() {

	string str;
	
	//²¹³äÊäÈë
	cin >> str;
	Replace(str, 'c', 'C');

	cout << str << endl;

	return 0;
	}

void Replace(string &a, const char b, const char c)
{
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == 'c')
			a[i] = 'C';
	}
}

