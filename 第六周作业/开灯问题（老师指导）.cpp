#define _CRT_SECURE_NO_WARNINGS //put in first line
#include<iostream>
#include<cstring>
int main()
{
	using namespace std;
	int n, k, i, j;
	int light[1007];
	int yah = 0;//开灯的个数
	cin >> n >> k;
memset(light, 0, sizeof(light));//清零数组
	for (i = 1; i <= n; i++)//从第一个学生开始
	{
		for (j = 1; j <= k; j++)//开始进人
		{
			if (i%j == 0)//如果这个人和这盏灯的编号成比例
			{
				light[i] = !light[i];//关上的灯再打开，打开的等关上，开关用“0”或“1”表示

				if (light[i] != 0)  ++yah;//记录最后一个开着的灯
			}
		}
	}
	//cout<<"yah"<<yah<<endl;
	for(int i=1;i<=n;i++)
		if(light[i]==1)
			yah=i;
	//cout<<"yah"<<yah<<endl;
	for (i = 1; i <= n; i++)
		if (light[i] != 0)//仍然开着的灯
		{
			if (i == yah) cout << i;
			else cout<<i<<" ";//对应编号
		}


	//int mark = 1;
	//for (i = 0; i <= n; i++)
	//{
	//	if (light[i] != 0)//仍然开着的灯
	//	{
	//	if (mark == 1) mark = 0;
	//		else cout << " ";//对应编号
	//	cout << i;
	//	}

	//}


	
	return 0;
}
