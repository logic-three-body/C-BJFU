#include<iostream>
#include<math.h>
int main()
{
	using namespace std;
	int n,count=0;
	cin >> n;
	while (n != 1)
	{
		if ((n % 2)==0)
		{
			n /= 2;
			
			count++;
		}
		else
		{
			n = 3 * n + 1;
			count++;
		}
		//count++;
	}
	//cout << n << endl;
	cout << count << endl;
	return 0;
}