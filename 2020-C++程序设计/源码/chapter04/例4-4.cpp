#include <iostream>
using namespace std;
class A
{
private:
	int x;
	int y;
public:
	A(int x1 = 0, int y1 = 0) :x(x1), y(y1){}
	friend ostream& operator<< (ostream& os, const A& a); //����<<�����
	friend istream& operator>> (istream& is, A& a); //����>>�����
};
ostream& operator<< (ostream& os, const A& a)
{
	os << "(" << a.x << "," << a.y << ")"; //���������ݳ�Ա
	return os;
}
istream& operator>> (istream& is, A& a)
{
	is >> a.x >> a.y; //������ĳ�Ա����
	return is;
}
int main()
{
	A a1(1, 2), a2(3, 4);
	cout << "a1:" << a1 << endl;
	cout << "a2:" << a2 << endl;

	cout << "������Ϊa2�����������ݣ�" << endl;
	cin >> a2;
	cout << "���������a2:" << a2 << endl;

	system("pause");
	return 0;
}
