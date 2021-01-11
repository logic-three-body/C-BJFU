#include<iostream>
using namespace std;
const int m = 3, n = 4;
int main()
{

	int a[m + 1][n + 1], b[101][4];
	int k = 0;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j];
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			if (a[i][j] != 0)
			{
				++k;
				b[k][1] = i;
				b[k][2] = j;
				b[k][3] = a[i][j];

			}
	for (int i = 1; i <= k; ++i)
	{
		for (int j = 1; j <= 3; ++j)
			cout << b[i][j];
		cout << endl;
	}
	return 0;
}