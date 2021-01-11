#include <iostream>
using namespace std;

class IntAddend;                                         //声明IntAddend被加数类
class IntAugend                                           //定义IntAugend加数类
{
public:
	IntAugend(int con_m)                               //定义构造函数
	{
		m_nM = con_m;
	}
	void add(IntAddend &ref_addend);
private:
	int m_nM;
};
class IntAddend                                         //定义IntAddend被加数类
{
public:
	IntAddend(int con_n)
	{
		m_nN = con_n;
	}
	//声明IntAugend类中的add()函数为本类的友元函数，可以直接访问本类私有成员
	friend void IntAugend::add(IntAddend &);
private:
	int m_nN;
};
void IntAugend::add(IntAddend &ref_addend)        //add()函数的定义
{
	//直接访问IntAddendd对象ref_addend中的私有成员m_nN
	cout << "addend: n = " << ref_addend.m_nN << ",m =  " << m_nM << endl;
	//对不同类中两个整型数据成员进行相加
	cout << m_nM << " + " << ref_addend.m_nN << " = "
		<< m_nM + ref_addend.m_nN << endl;
}
int main()
{
	IntAugend intnum1(5);                            //定义IntAugend类对象intnum1
	IntAddend intnum2(3);                            //定义IntAugend类对象intnum1
	intnum1.add(intnum2);                            //调用add()函数实现数据相加
	system("pause");
	return 0;
}
