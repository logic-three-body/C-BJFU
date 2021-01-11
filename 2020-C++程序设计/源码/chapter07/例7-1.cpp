#include <iostream>
using namespace std;
int main()
{
	int m = 10, n = 0; //定义两个整型变量，m将作为被除数，n作为除数
	cout << "m / n = " << m / n << endl; //除零，引发异常
	return 0;
}
