#define _CRT_SECURE_NO_WARNINGS //put in first line
#include<iostream>
#include<cstring>
int main()
{
	using namespace std;
	int n, k, i, j;
	int light[1007];
	int yah = 0;//���Ƶĸ���
	cin >> n >> k;
memset(light, 0, sizeof(light));//��������
	for (i = 1; i <= n; i++)//�ӵ�һ��ѧ����ʼ
	{
		for (j = 1; j <= k; j++)//��ʼ����
		{
			if (i%j == 0)//�������˺���յ�Ƶı�ųɱ���
			{
				light[i] = !light[i];//���ϵĵ��ٴ򿪣��򿪵ĵȹ��ϣ������á�0����1����ʾ

				if (light[i] != 0)  ++yah;//��¼���һ�����ŵĵ�
			}
		}
	}
	//cout<<"yah"<<yah<<endl;
	for(int i=1;i<=n;i++)
		if(light[i]==1)
			yah=i;
	//cout<<"yah"<<yah<<endl;
	for (i = 1; i <= n; i++)
		if (light[i] != 0)//��Ȼ���ŵĵ�
		{
			if (i == yah) cout << i;
			else cout<<i<<" ";//��Ӧ���
		}


	//int mark = 1;
	//for (i = 0; i <= n; i++)
	//{
	//	if (light[i] != 0)//��Ȼ���ŵĵ�
	//	{
	//	if (mark == 1) mark = 0;
	//		else cout << " ";//��Ӧ���
	//	cout << i;
	//	}

	//}


	
	return 0;
}
