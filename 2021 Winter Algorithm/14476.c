#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int GCD(int a, int b) {
	return b ? GCD(b, a%b) : a;
}

int main() {
	int i, N, gcd;
	int num[10000];
	int gcdLtoR[10000];
	int gcdRtoL[10000];
	int max = 0;
	int max_index = 0;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	gcdLtoR[0] = num[0];
	gcdRtoL[N - 1] = num[N - 1];

	for (i = 1; i < N; i++) {
		gcdLtoR[i] = GCD(gcdLtoR[i - 1], num[i]);
	}
	for (i = N-2; i >=0; i--) {
		gcdRtoL[i] = GCD(gcdRtoL[i + 1], num[i]);
	}

	for (i = 0; i < N; i++) {
		gcd = 0;
		if (i == 0) {
			gcd = gcdRtoL[1];
		}
		else if (i == N - 1) {
			gcd = gcdLtoR[N - 2];
		}
		else {
			gcd = GCD(gcdLtoR[i - 1], gcdRtoL[i + 1]);
		}

		if (num[i] % gcd != 0 && gcd > max) {
			max = gcd;
			max_index = i;
		}
	}

	if (max == 0 && max_index == 0) {
		printf("-1\n");
	}
	else {
		printf("%d %d\n", max, num[max_index]);
	}

	return 0;
}