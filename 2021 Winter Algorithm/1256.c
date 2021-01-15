#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define max 1000000000

int main() {
	int D[201][201];
	int N, K, Q;
	int i, j;
	int temp_N, temp_K, cnt;
	char result[202] = {'0'};
	int result_cnt = 0;

	scanf("%d %d %d", &N, &K, &Q);

	for (i = 1; i <= N + K; i++) {
		for (j = 0; j <= K; j++) {
			if (i == j || j == 0) {
				D[i][j] = 1;
			}
			else {
				if (D[i - 1][j] + D[i - 1][j - 1] > max) {
					D[i][j] = max + 1;
				}
				else {
					D[i][j] = D[i - 1][j] + D[i - 1][j - 1];
				}
			}
		}
	}

	if (D[N + K][K] < Q) {
		printf("-1\n");
		return 0;
	}

	temp_N = N + K;
	temp_K = K;
	cnt = 0;

	while (temp_N >= 1) {
		if (temp_N == 1) {
			if (temp_K == 0) {
				result[result_cnt++] = 'a';
				break;
			}
			else if (temp_K == 1) {
				result[result_cnt++] = 'z';
				break;
			}
		}

		if (Q <= cnt + D[temp_N - 1][temp_K]) {
			temp_N--;
			result[result_cnt++] = 'a';
		}
		else {
			cnt += D[temp_N - 1][temp_K];
			temp_N--;
			temp_K--;
			result[result_cnt++] = 'z';
		}
	}
	printf("%s\n", result);

	return 0;
}