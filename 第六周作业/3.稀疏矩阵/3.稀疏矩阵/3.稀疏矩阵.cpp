#include<iostream>

//const int R = 3;
//const int C = 4;

int main()
{
	using namespace std;
	int a[100][100];
	int b[100][100];
	int R, C;
	cin >> R >> C;
	for (int i = 0; i < R; ++i)   //value to 2D array
	{
		for (int j = 0; j < C; ++j)
		{
			cin >> a[i][j];			
		}	
	}
	
	//for (int i = 0; i < R; i++)
	//{
	//	for (int j = 0; j < C; j++)
	//	{
	//		cout << a[i][j] << " ";
	//	}
	//	cout << endl;

	//}

	int k = 0;
	for (int i = 0; i < R; ++i)   //test the value!=0
	{
		for (int j = 0; j < C;++j)
		{
			if (a[i][j] != 0)
			{
				//++k;//放这里会跳过b的第0行，导致输出结果第一行为地址
				b[k][0] = i+1;//send row and column
				b[k][1] = j+1;
				b[k][2] = a[i][j];
				++k;//注意k++的位置！！！
			}
		}
	}

	for (int i = 0; i < k; ++i)   //value to 2D array
	{
		for (int j = 0; j < 3; ++j)
		{
			if (2 == j) cout << b[i][j];
			else cout << b[i][j] << " ";
		}
		cout << endl;
	}

	//cout << k;
	

	return 0;
}