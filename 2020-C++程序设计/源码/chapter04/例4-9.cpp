#include <iostream>
using namespace std;
class Swap
{
private:
	int a, b;
public:
	Swap(int m, int n) :a(m), b(n){}
	Swap(double c)  //ת�����캯��
	{
		cout << "swap constructor is calling" << endl;
		a = static_cast<int>(c);
		b = 0;
	}
	void show()
	{
		cout << a << " " << b << endl;
	}
};
int main()
{
	Swap s1(1, 2); //������ͨ���캯����������
	Swap s2(3.2); //����ת�����캯��
	cout << "s1: ";
	s1.show();
	cout << "s2: ";
	s2.show();

	system("pause");
	return 0;
}
