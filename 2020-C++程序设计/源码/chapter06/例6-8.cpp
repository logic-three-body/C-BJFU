#include <iostream>
#include <fstream>  //包含fstream头文件
using namespace std;
int main()
{
	ifstream ifs;  //构造输入流
	ifs.open("C:\\Users\\www\\Desktop\\a.txt", ios::in); //以输入方式打开
	
	if (!ifs)
		cout << "open failed" << endl;
	else
		cout << "open success" << endl;
	ifs.close();
	system("pause");
	return 0;
}
