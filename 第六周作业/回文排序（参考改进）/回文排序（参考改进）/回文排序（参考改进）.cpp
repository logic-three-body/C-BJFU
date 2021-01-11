#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct input {
	string s;
	int order;
}c[55];
bool ishuiwen(string x)
{
	for (int i = 0; i < x.size() / 2; i++)
	{
		if (x[i] != x[x.size() - 1 - i])return false;
	}
	return true;
}
bool comp(input a, input b)
{
	if (a.s.size() != b.s.size())return a.s.size() < b.s.size();
	return a.order < b.order;
}
int main()
{
	string a;
	int b;
	cin >> b;
	int fin = 0;
	while (fin<b)
	{
		int num = 0;
		for (int i = 0; i < b; i++)
		{
			cin >> a;
			if (ishuiwen(a)) {
				c[num].s = a;
				c[num++].order = num;
			}
		}
		sort(c, c + num, comp);
		for (int i = 0; i < num; i++)
		{
			cout << c[i].s << endl;
		}
		fin++;
	}
	return 0;
}
