#include <iostream>
using namespace std;
class Base{
public:
	Base(int con_n) :n(con_n){};
	void output(){ cout << n << endl; }
private:
	int n;
};
int main()
{
	Base *p = new Base[3]{Base(1), Base(2), Base(3)};
	for (int i = 0; i < 3; i++)
		p[i].output();
	system("pause");
	return 0;
}
