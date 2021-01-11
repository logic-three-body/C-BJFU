#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Internet
{
public:   //Ϊ�˺���������㣬��ԱȨ�����ó�Ϊpublic
	char* name;
	char* url;
public:
	Internet(char* name, char* url); //���캯��
	Internet(Internet& temp); //�������캯��
	~Internet()
	{
		delete[]name;
		delete[]url;
	}
	Internet& operator= (Internet& temp); //��ֵ���������
};

//��Internet��Ա������ʵ��
Internet::Internet(char* name, char* url)  //���캯��ʵ��
{
	this->name = new char[strlen(name) + 1];
	this->url = new char[strlen(url) + 1];
	if (name)
		strcpy(this->name, name);
	if (url)
		strcpy(this->url, url);
}

Internet::Internet(Internet& temp)  //�������캯��ʵ��
{
	this->name = new char[strlen(temp.name) + 1];
	this->url = new char[strlen(temp.url) + 1];
	if (name)
		strcpy(this->name, temp.name);
	if (url)
		strcpy(this->url, temp.url);
}

Internet& Internet:: operator= (Internet& temp)
{
	delete[]name;
	delete[]url;  //���ͷ�ԭ���ռ䣬����������
	this->name = new char[strlen(temp.name) + 1];
	this->url = new char[strlen(temp.url) + 1];
	if (name)
		strcpy(this->name, temp.name);
	if (url)
		strcpy(this->url, temp.url);

	return *this;
}

int main()
{
	Internet a("���ǲ���", "http://net.itcast.cn/");
	cout << "a���� " << a.name << " " << a.url << endl;

	Internet b(a);  //��a�����ʼ��b�����õ��ǿ������캯��
	cout << "b���� " << b.name << " " << b.url << endl;

	Internet c("����ѵ��Ӫ", "http://www.itheima.com/");
	cout << "c���� " << c.name << " " << c.url << endl;

	b = c; //���ø�ֵ���غ���
	cout << "b���� " << b.name << " " << b.url << endl;
	system("pause");
	return 0;
}
