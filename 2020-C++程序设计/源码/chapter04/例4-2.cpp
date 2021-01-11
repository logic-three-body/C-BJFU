#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class A
{
private:
	int x;
	int y;
public:
	A(int x1 = 0, int y1 = 0) :x(x1), y(y1){}
	void show() const; //�������
	A operator++();  //����ǰ��++
	A operator++(int); //���غ���++
};

void A::show() const
{
	cout << "(x,y) = " << "(" << x << "," << y << ")" << endl;
}
A A::operator++()  //ǰ��++ʵ��
{
	++x;
	++y;
	return *this;
}
A A::operator++(int) //����++ʵ��
{
	A a = *this;
	++(*this);  //�����Ѿ�ʵ�ֵ�ǰ��++
	return a;
}
int main()
{
	A a1(1, 2), a2(3, 4);
	(a1++).show();
	(++a2).show();

	system("pause");
	return 0;
}
