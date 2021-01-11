#define _CRT_SECURE_NO_WARNINGS //put in first line
#include <stdio.h>
int main() {
	int a[100][100];
	int m, n, M, N, x, y, i, j, t = 0;
	scanf("%d", &M);
	N = M;
	for (x = 0, y = M - 1; N > 0; N = N - 2, x++, y--) {
		for (m = x, n = y, i = 0; i < N; i++, m++) {
			t++;
			a[m][n] = t;
		}
		for (m = y, n = y - 1, i = N - 2; i >= 0; i--, n--) {
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
		for (j = 0; j < M; j++) printf("%d ", a[i][j]);
		printf("\n");
	}
}