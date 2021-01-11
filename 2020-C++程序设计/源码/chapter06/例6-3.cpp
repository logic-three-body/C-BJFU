#include <iostream>
using namespace std;
int main()
{
	cout << "first call: " << cin.get() << endl;  //第一种形式调用

	char ch;
	cin.get(ch); //第二种形式调用
	cout << "second call: " << ch << endl;

	char str[10];
	cin.get(str, 8, 'T'); //第三种形式调用
	cout << "third call: " << str << endl;
	system("pause");
	return 0;
}
