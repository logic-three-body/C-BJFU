#include <iostream>
using namespace std;
template<typename T, unsigned size> //非类型模板参数unsigned size
class Array{
	T arr[size];
public:
	T& operator[](unsigned i)
	{
		if (i >= size)
			cout << "out of the bound" << endl;
		else
			return arr[i];
	}
};
int main()
{
	Array<char, 5> arr1;  //定义一个长度为5的char类型数组
	Array<int, 10> arr2;  //定义一个长度为10的int数组
	arr1[0] = 'A';
	cout << arr1[0] << endl;
	for (int i = 0; i < 10; i++)//为int类型数组arr2赋值并输出
		arr2[i] = i + 1;
	for (int i = 0; i < 10; i++)
		cout << arr2[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}
