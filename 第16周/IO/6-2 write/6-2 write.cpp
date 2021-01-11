#include <iostream>
using namespace std;
int main()
{
	const char* p = "chuan zhi bo ke";
	cout.write(p, 8).put('\n');
	cout.write(p, strlen(p)) << endl;
	cerr << p<<endl;
	clog << p<<endl;
	
	system("pause");
	return 0;
}
