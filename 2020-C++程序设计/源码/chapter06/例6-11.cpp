#include <iostream>
#include <fstream>
using namespace std;
struct Student
{
	char name[20];
	int age;
	char sex;
};
struct Date
{
	int mondy, day, year;
};
int main()
{
	//写文件
	Student sts[3];
	cout << "please input 3 students' data:" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> sts[i].name >> sts[i].age >> sts[i].sex;
	}
	ofstream ofs("C:\\Users\\www\\Desktop\\a.dat", ios::out | ios_base::binary);
	
	if (!ofs)
	{
		cerr << "open failed" << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		ofs.write(reinterpret_cast<char*>(&sts[i]), sizeof(sts[i]));
		ofs.flush();
	}
	ofs.close();
	cout << "write over!" << endl << "read from a.dat:" << endl;
	//读文件
	ifstream ifs("C:\\Users\\www\\Desktop\\a.dat", ios::in | ios_base::binary);
	
	if (ifs)
	{
		Student sts1[3];
		for (int i = 0; i < 3; i++)
		{
			ifs.read(reinterpret_cast<char*>(&sts1[i]), sizeof(sts1[i]));
			cout << sts1[i].name << " " << sts1[i].age << " " << sts1[i].sex << endl;
		}
	}
	else
		cout << "ifs failed" << endl;
	ifs.close();
	system("pause");
	return 0;
}
