#include <iostream>
#include <strstream>
using namespace std;
int main()
{
	char buf[50] = "12 25 68 -68 25 27 15 65 69 144";
	int arr[10];
	cout << "buf: " << buf << endl;

	istrstream istr(buf, sizeof(buf)); //构造输入字符串流与buf关联
	for (int i = 0; i < 10; i++)
		istr >> arr[i];  //从字符数组buf中读入10个整数赋给整型数组arr
	cout << "arr: ";
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl;

	for (int i = 0; i < 9; i++)  //冒泡法对数组arr进行排序
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}

		}
	}
	ostrstream ostr(buf, sizeof(buf)); //构造输出字符串流与buf关联
	for (int i = 0; i < 10; i++)
		ostr << arr[i] << " "; //将10个整数存放入字符数组buf
	ostr << ends;  //ends是C++的I/O操作符，插入一个'\0'
	cout << "buf: " << buf << endl;

	system("pause");
	return 0;
}
