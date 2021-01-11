#include<iostream>
using namespace std;
int main()
{
	char str[10];
	cin.ignore(6, 'T'); //跳过前面6个字符，如果有T，则T终止跳跃
	cin.getline(str, 8);//开始读取输入的字符串，存储到str中
	cout << str << endl;
	system("pause");
	return 0;
}
