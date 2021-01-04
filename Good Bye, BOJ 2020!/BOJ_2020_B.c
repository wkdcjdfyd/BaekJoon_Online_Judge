/*
	20529번
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Count(char arr[][4], int N) {
	int i, j, k, o, cnt;
	int min = 30;

	for (i = 0; i < N - 2; i++) {
		for (j = i + 1; j < N - 1; j++) {
			for (k = j + 1; k < N; k++) {
				cnt = 0;
				for (o = 0; o < 4; o++) {
					if (arr[i][o] != arr[j][o]) {
						cnt++;
					}
					if (arr[i][o] != arr[k][o]) {
						cnt++;
					}
					if (arr[j][o] != arr[k][o]) {
						cnt++;
					}
				}
				if (min > cnt) {
					min = cnt;
				}
			}
		}
	}
	return min;
}

int main() {
	int T, N;
	int l, m;
	char arr[100000][4];
	int min;

	scanf("%d", &T);

	for (m = 0; m < T; m++) {
		scanf("%d", &N);

		if (N > 33) {			//비둘기집 원리 → 16*2 + 1 = 33개 이상이면 같은 MBTI가 3번 이상 나올 확률↑
			printf("0\n");
			continue;
		}

		for (l = 0; l < N; l++) {
			scanf("%s", arr[l]);
		}
		min = Count(arr, N);

		printf("%d\n", min);
	}

	return 0;
}
