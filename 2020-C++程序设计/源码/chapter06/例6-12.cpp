#include <iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream ifs; //构造输入流对象
	ifs.open("C:\\Users\\www\\Desktop\\a.txt", ios::in | ios::out | ios::binary);
	
	cout << "ifs first: " << ifs.tellg() << endl;  //打开文件后查看指针位置
	ifs.seekg(6); //将位置指针向后移动6个字节
	cout << "ifs second: " << ifs.tellg() << endl; //移动指针后再查看指针位置
	char ch;
	ifs.get(ch); //获取当前指针处的字符
	cout << "get cur char: " << ch << endl;

	ofstream ofs;  //构造输出流对象
	ofs.open("C:\\Users\\www\\Desktop\\a.txt", ios::in | ios::out | ios::binary);
	
	cout << "ofs first: " << ofs.tellp() << endl; //输出流打开文件后，查看指针位置
	ofs.seekp(3);  //将指针向后移动3个字节
	cout << "ofs second: " << ofs.tellp() << endl; //设置后再查看指针位置
	ofs.put('A'); //向当前指针处写入字符A，替换掉原来的字符
	ifs.seekg(ios::beg);  //将输入流的文件位置指针移动到开头
	char buf[20];
	while (!ifs.eof()) //读取文件并输出
	{
		ifs.getline(buf, 20, '\n');
		cout << "buf: " << buf << endl;
	}
	ifs.close();
	ofs.close();

	system("pause");
	return 0;
}
