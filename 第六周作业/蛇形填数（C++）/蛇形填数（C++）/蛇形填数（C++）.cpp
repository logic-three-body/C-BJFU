#define _CRT_SECURE_NO_WARNINGS //put in first line
#include <iostream>
int main() {
	using namespace std;
	int a[100][100];
	/*����һ����ά���飬 �� x �����У� y ������������˳���� �£� �� �ϣ� ��
   ֱ��һ�������޷�������ʱ���ٽ�����һ�����������*/		
	//cin >> M;
	int M;
	while (cin >> M)
	{
		int m, n, N, x, y, i, j, t = 0;
		N = M;		
		for (x = 0, y = M - 1; N > 0; N = N - 2, x++, y--) {//�ӵ�0�У������һ�У���3�У���������У���ʼ
			for (m = x, n = y, i = 0; i < N; i++, m++) { //�в��������������������һ��
				t++;
				a[m][n] = t;
			}
			for (m = y, n = y - 1, i = N - 2; i >= 0; i--, n--) {//���һ������һ�У���գ�������в���
				t++;
				a[m][n] = t;
			}
			for (m = y - 1, n = x, i = N - 2; i >= 0; i--, m--) {
				t++;
				a[m][n] = t;
			}
			for (m = x, n = x + 1, i = 1; i < N - 1; i++, n++) {
				t++;
				a[m][n] = t;
			}
		}
		for (i = 0; i < M; i++) {
			for (j = 0; j < M; j++)
			{
				if (j == M - 1) cout << a[i][j];
				else cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
	
}