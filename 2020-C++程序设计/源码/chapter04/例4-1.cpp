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
	A operator+(const A& a) const; //����+�����
	A operator- (const A& a) const; //����-�����
};
//���Ա������ʵ��
void A::show() const  //show()������ʵ��
{
	cout << "(x,y) = " << "(" << x << "," << y << ")" << endl;
}

A A::operator+(const A& a) const //����+�������ʵ��
{
	return A(x + a.x, y + a.y);
}

A A::operator-(const A& a) const //����-�������ʵ��
{
	return A(x - a.x, y - a.y);
}
//main()��������
int main()
{
	A a1(1, 2);
	A a2(4, 5);
	A a;
	cout << "a1: ";
	a1.show();
	cout << "a2: ";
	a2.show();
	a = a1 + a2;  //ʵ�������������
	cout << "a: ";
	a.show();
	a = a1 - a2; //ʵ�������������
	cout << "a: ";
	a.show();
	system("pause");
	return 0;
}
