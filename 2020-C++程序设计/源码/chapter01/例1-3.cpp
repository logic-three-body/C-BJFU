#include <iostream>
using namespace std;
int main()
{
	int num = 100;
	const int* p1 = &num;
	int* p2 = const_cast<int*>(p1);  //将常量指针p1转换为普通指针类型，去掉const属性
	*p2 = 200;
	cout << "num =  " << num << endl;
	system("pause");
	return 0;
}
