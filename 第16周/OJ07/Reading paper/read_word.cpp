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
	stringstream sstr(txt);//将文章读入sstr,空格会自动区分多少个字符串
	string temp;
	int words = 0;
	int symbols = 0;
	while (sstr >> temp)
	{
		++words;
		for (char content : temp)//文章里每一个字符串（单词）的每一个字母读入content
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