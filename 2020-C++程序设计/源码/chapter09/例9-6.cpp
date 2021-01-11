#include <iostream>
using namespace std;
template <class T1, class T2>
void cpbybyte(T1& x, T2& y)
{
	static_assert(sizeof(x) == sizeof(y), "the parameters must be the same width.");
};
int main()
{
	int n;
	char c;
	cpbybyte(n, c);
	return 0;
}
