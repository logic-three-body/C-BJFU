#include <iostream>
#include <sstream>
#include <string>
#include<cstdlib>
using namespace std;
int main()
{
	ostringstream ostr;
	ostr.str("abc");
	//��������ʱ���������ַ�������,��ô����������ʱ�򲻻�ӽ�β��ʼ����,�����޸�ԭ������,�����Ĳ�������
	ostr.put('d');
	ostr.put('e');
	ostr << "fg";

	string gstr = ostr.str();
	cout << gstr;
	system("pause");
}

/*
�����������У�����ͨ��put()�������Ʋ��������Բ�����ostr���뵥���ַ��������ַ�����ͨ��str()����������������������ַ������ݣ���ֵ ��ע���һ���ǣ��������ʱ��������Ѿ������ַ������ݵ�ʱ����ô����������ʱ�򲻻�ӽ�β��ʼ����,�����޸�ԭ������,�����Ĳ���������
[ basic_stringbuf::str :
Sets or gets the text in a string buffer without changing the write position. ]

��������stringstream����˵�������Ҷ�˵�����Ҳ�Ѿ�֪����������C++�����ַ�������������ġ�
stringstream�Ĺ��캯��ԭ�����£�

����stringstream::stringstream(string str);
*/