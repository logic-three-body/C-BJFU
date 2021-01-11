#include<iostream>
#include<stack>
using namespace std;

const int MAX = 1000;
int n, rail[MAX];
int main()
{
	while (cin >> n)
	{
		stack<int> st;
		for (int i = 1; i <= n; i++)
		{
			cin >> rail[i];
		}

		int flag, a, b;
		a = b = flag = 1;
		while (b <= n)
		{
			if (a == rail[b])
			{
				++a;
				++b;
			}
			else if (!st.empty() && st.top() == rail[b])
			{
				st.pop();
				++b;
			}
			else if (a <= n)//top最大值是n-1
			{
				st.push(a++);
			}
			else
			{
				flag = 0;
				break;
			}
		}
		printf("%s\n", flag ? "Yes" : "No");
	}
	return 0;
}