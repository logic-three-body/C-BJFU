#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
using namespace std;
void readPapers(const string&txt)
{
	//getline(cin, txt);
	//cin.getline(txt, txt.length());
	//int n = strlen(txt);
	stringstream sstr(txt);//�����¶���sstr,�ո���Զ����ֶ��ٸ��ַ���
	string temp;
	int words = 0;
	int symbols = 0;
	while (sstr >> temp)
	{
		++words;
		for (char content : temp)//������ÿһ���ַ��������ʣ���ÿһ����ĸ����content
		{
			if ('.' == content || ',' == content || '"'==content)
			{
				++symbols;
			}
		}
	}
	cout<<words<<","<<symbols<<endl;
}


int main() {
	std::string content;
	std::getline(std::cin, content, '\n');
	readPapers(content);
	return 0;
}