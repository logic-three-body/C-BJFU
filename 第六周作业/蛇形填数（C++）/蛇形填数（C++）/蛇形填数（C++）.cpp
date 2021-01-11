#define _CRT_SECURE_NO_WARNINGS //put in first line
#include <iostream>
int main() {
	using namespace std;
	int a[100][100];
	/*设置一个二维数组， 以 x 代表行， y 代表列填数的顺序是 下， 左， 上， 右
   直到一个方向无法再填数时，再进行下一个方向的填数*/		
	//cin >> M;
	int M;
	while (cin >> M)
	{
		int m, n, N, x, y, i, j, t = 0;
		N = M;		
		for (x = 0, y = M - 1; N > 0; N = N - 2, x++, y--) {//从第0行（矩阵第一行）第3列（矩阵第四列）开始
			for (m = x, n = y, i = 0; i < N; i++, m++) { //列不动，按行填数，填最后一列
				t++;
				a[m][n] = t;
			}
			for (m = y, n = y - 1, i = N - 2; i >= 0; i--, n--) {//最后一列填到最后一行，左拐，向上填，列不动
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