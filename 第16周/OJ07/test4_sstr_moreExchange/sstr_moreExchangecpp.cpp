#include <iostream>
#include <sstream>
#include <string>
#include<cstdlib>
using namespace std;

int main()
{
stringstream sstr;
//--------int转string-----------
int a=100;
string str;
sstr<<a;
sstr>>str;
cout<<str<<endl;
//--------string转char[]--------
sstr.clear();//如果你想通过使用同一stringstream对象实现多种类型的转换，请注意在每一次转换之后都必须调用clear()成员函数。
string name = "colinguan";
char cname[200];
sstr<<name;
sstr>>cname;
cout<<cname;
system("pause");
}