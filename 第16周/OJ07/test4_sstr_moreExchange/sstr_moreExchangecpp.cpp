#include <iostream>
#include <sstream>
#include <string>
#include<cstdlib>
using namespace std;

int main()
{
stringstream sstr;
//--------intתstring-----------
int a=100;
string str;
sstr<<a;
sstr>>str;
cout<<str<<endl;
//--------stringתchar[]--------
sstr.clear();//�������ͨ��ʹ��ͬһstringstream����ʵ�ֶ������͵�ת������ע����ÿһ��ת��֮�󶼱������clear()��Ա������
string name = "colinguan";
char cname[200];
sstr<<name;
sstr>>cname;
cout<<cname;
system("pause");
}