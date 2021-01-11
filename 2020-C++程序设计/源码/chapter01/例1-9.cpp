#include <iostream>
using namespace std;
void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}
int main()
{
	int a, b;
	cout << "please input two nums: " << endl;
	cin >> a >> b;
	swap(a, b);
	cout << "swap: " << a << " " << b << endl;
	system("pause");
	return 0;
}
