#include <iostream>
using namespace std;

class IntClass                                           //定义IntClass类
{
public:
	IntClass(int con_n, int con_m);
	friend int add(IntClass &);                       //声明普通函数add()为友元函数
private:
	int m_nN, m_nM;
};

IntClass::IntClass(int con_n, int con_m)
{
	m_nN = con_n;
	m_nM = con_m;
}

int add(IntClass &refnum)                             //定义普通函数add()
{
	//本函数是IntClass的友元函数，可以直接访问私有成员，实现两个私有数据成员的相加
	return refnum.m_nN + refnum.m_nM;
}

int main()
{
	IntClass intnum(5, 7);                             //创建类对象
	cout << "add(5, 7) = " << add(intnum) << endl;//调用add()函数
	system("pause");
	return 0;
}
