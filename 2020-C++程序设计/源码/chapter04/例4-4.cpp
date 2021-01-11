#include <iostream>
using namespace std;
class A
{
private:
	int x;
	int y;
public:
	A(int x1 = 0, int y1 = 0) :x(x1), y(y1){}
	friend ostream& operator<< (ostream& os, const A& a); //重载<<运算符
	friend istream& operator>> (istream& is, A& a); //重载>>运算符
};
ostream& operator<< (ostream& os, const A& a)
{
	os << "(" << a.x << "," << a.y << ")"; //输出类的数据成员
	return os;
}
istream& operator>> (istream& is, A& a)
{
	is >> a.x >> a.y; //输入类的成员数据
	return is;
}
int main()
{
	A a1(1, 2), a2(3, 4);
	cout << "a1:" << a1 << endl;
	cout << "a2:" << a2 << endl;

	cout << "请重新为a2对象输入数据：" << endl;
	cin >> a2;
	cout << "重新输入后a2:" << a2 << endl;

	system("pause");
	return 0;
}
