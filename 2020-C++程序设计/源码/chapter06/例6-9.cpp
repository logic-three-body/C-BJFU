#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	char buf[256];
	ifstream ifs("C:\\Users\\www\\Desktop\\a.txt");

	cout << "a.txt 内容如下：" << endl;
	while (!ifs.eof()) //判断文件是否达到结尾
	{
		ifs.getline(buf, 256, '\n'); //调用基类的getline()成员函数
		cout << buf << endl;
	}
	ifs.close();
	system("pause");
	return 0;
}
