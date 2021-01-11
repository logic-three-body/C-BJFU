#include <iostream>
using namespace std;
int main()
{
	int *pi = new int(10); //new 一个int对象，初始值为10
	cout << "*pi = " << *pi << endl;
	*pi = 20;    //通过指针改变变量的值
	cout << "*pi = " << *pi << endl;
	char *pc = new char[10];
	for (int i = 0; i < 10; i++)
		pc[i] = i + 65;    //向数组中存入元素
	for (int i = 0; i < 10; i++)
		cout << pc[i] << " ";
	cout << endl;
	delete pi;      //释放int对象
	delete[]pc;    //释放数组对象
	system("pause");
	return 0;
}
