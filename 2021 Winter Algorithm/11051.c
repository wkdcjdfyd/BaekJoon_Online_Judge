#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j;
	int N, K;
	int D[1001][1001];

	scanf("%d %d", &N, &K);

	for (i = 1; i <= N; i++) {
		for (j = 0; j <= K; j++) {
			if (i == j || j == 0) {
				D[i][j] = 1;
			}
			else {
				D[i][j] = (D[i - 1][j] + D[i - 1][j - 1]) % 10007;
			}
		}
	}

	printf("%d\n", D[N][K]);

	return 0;
}