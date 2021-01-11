#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ofstream ofs;
	//打开文件，trunc是打开文件前将文件清空
	ofs.open("C:\\Users\\www\\Desktop\\a.txt", ios::trunc);

	char ch = 'a';
	if (ofs)  //判断文件是否打开成功
	{
		for (int i = 0; i < 26; i++)
		{
			if (i&&i % 5 == 0)  //到第5个字符时换行
				ofs << endl;
			ofs << ch; //直接调用<<运算符进行写入
			ch++;
		}
		cout << "write success" << endl;
	}
	else
		cout << "write failed" << endl;
	ofs.close();
	system("pause");
	return 0;
}
