#include<iostream>
#include<map>
#include<algorithm>
#include<string>
#include <sstream>
using namespace std;
unsigned termFrequency(string&txt, map<string, unsigned>&match)
{
	stringstream sstr(txt);
	string temp;
	while (sstr >> temp)//once read a splited string
	{
		//remove the punct
		temp.erase(remove(temp.begin(), temp.end(), '.'), temp.end());
		temp.erase(remove(temp.begin(), temp.end(), ','), temp.end());
		temp.erase(remove(temp.begin(), temp.end(), '"'), temp.end());

		//number judgement
		stringstream Is_it_num(temp);
		int num;
		if (Is_it_num >> num)
			continue;

		//to lower type
		//transform(temp.begin(), temp.end(), temp.begin(), tolower);
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

		map<string, unsigned>::iterator it;
		it = match.find(temp);//find the element or return end
		if (match.end() == it)//match doesn't have temp
			match.insert(pair<string, unsigned>(temp, 1));//if the word doesn't occur once then insert it into map
		else
			match[temp]++;

	}
	//cout << match.size();
	return match.size();
}


void alphabetSortedFrequency(map<string, unsigned>&match)
{
	//map key default sort
	map<string, unsigned>::iterator it;
	for (it = match.begin(); it != match.end(); ++it)
	{
		cout << it->first << ":" << it->second << endl;
	}
}


int main() {

	// 从标准输入获取文本串
	std::string content;
	std::getline(std::cin, content, '\n');

	map<string, unsigned> msu;

	// 要求termFrequency实现分词，去掉标点
	// 获取单词存放在map中，记录词频（出现次数）
	// 最后返回不重复的单词数量    
	unsigned nWords = termFrequency(content, msu);

	// 按首字母A-Z排序一行一词输出词频
	alphabetSortedFrequency(msu);

	return 0;
}