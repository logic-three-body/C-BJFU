#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int x, int y)
{
	return x < y;
}

int main()
{
	int N, Q;
	while (cin >> N >> Q)
	{
		int marble[1000];
		for (int i = 0; i < N; ++i)
		{
			cin >> marble[i];
		}
		//sort(marble, marble + N, cmp);

		sort(marble, marble + N);
		while (Q--)
		{
			int que, local;
			cin >> que;
			local = lower_bound(marble, marble + N, que) - marble + 1;//让数组下标和数字对齐 4->5
			if (marble[local - 1] != que)
			{
				cout << que << " not found " << endl;

			}
			else
			{
				cout << que << " found at " << local << endl;
			}
		}

	}

	return 0;
}