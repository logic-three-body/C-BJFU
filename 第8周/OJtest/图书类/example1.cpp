#define _CRT_SECURE_NO_WARNINGS //put in first line
#include <iostream>
#include<cstring>
using namespace std;

class Book
{
private:
	char *name;                //书名
	char *author;              //作者
	int sale;                  //销售量
public:
	Book();                               //无参构造函数
	Book(char *a, char *b, int c);         //有参构造函数
	Book(const Book &);                   //拷贝构造函数
	void print();                          //显示数据
	~Book();                              //析构函数
};

Book::Book(char*a,char*b, int c)    //定义带参数的构造函数
{
	name = new char[strlen(a) + 1];
	strcpy(name, a);//赋值书名
	author = new char[strlen(b) + 1];
	strcpy(author, b);//赋值作者
	sale = c;
}

Book::Book(const Book &which)                         //定义拷贝构造函数
{
	 name = new char[strlen(which.name) + 1];
	 strcpy(name, which.name);
	 author = new char[strlen(which.author) + 1];
     strcpy(author, which.author);
	 sale = which.sale;
}
Book::Book()//用户未输入时展示初始值
{
		sale = 0;
		name = new char[100];
		strcpy(name, "No name");
		author = new char[100];
		strcpy(author, "No author");

}
Book::~Book()                                          //定义析构函数
{
   delete[] author;
   delete[] name;
}
void Book::print()                               //定义pirnt()函数，显示属性值
{
	cout << "Name: " << name << "\t" << "Author: " << author << "\t" << "Sale: " << sale << endl;
}
int main()
{
	char *name1 = new char[100];
	char *name2 = new char[100];
	int num;
	cin.getline(name1, 100);
	cin.getline(name2, 100);
	cin >> num;
    if (strcmp(name1, "-1") == 0 && strcmp(name2, "-1") == 0 && num == -1)
	{
     Book bk1;
     bk1.print();
	 }
   else if (strcmp(name1, "0") == 0 && strcmp(name2, "0") == 0 && num == 0)
   {
     Book bk1;
	 Book bk2(bk1);
     bk2.print();
	     }
  else
   {
	Book bk1(name1, name2, num);
    bk1.print();
	 }
	delete[]name1;
	delete[]name2;
	return 0;
}
