#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	istringstream istr;
	istr.str("1 56.7");
	//�����������̿��Լ�д�� istringstream istr("1 56.7");
	cout << istr.str() << endl;
	int a;
	float b;
	istr >> a;
	cout << a << endl;
	istr >> b;
	cout << b << endl;
	return 0;
}

/*�����У������ַ�������ʱ�򣬿ո���Ϊ�ַ����������ڲ��ֽ磬�����ж�a,b���������"��ֵ"����֤������һ�㣬�ַ����Ŀո��Ϊ�����������븡�������ݵķֽ�㣬���÷ֽ��ȡ�ķ���������ʵ��������ַ��������Ͷ����븡���Ͷ���Ĳ��ת�����̡�

����str()��Ա������ʹ�ÿ�����istringstream���󷵻�һ��string�ַ��������籾���е��������(cout<<istr.str();����

����ostringstreamͬ������һ��string�����������ostringstream����һ��string�����ַ���
ostringstream�Ĺ��캯��ԭ�����£�
ostringstream::ostringstream(string str);

*/