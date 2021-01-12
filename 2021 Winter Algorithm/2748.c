#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long Fibo(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	else if (n == 2) {
		return 1;
	}
	long long a = 1;
	long long b = 1;
	long long c = 1;
	int i;

	for (i = 3; i <= n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

int main() {
	int N;
	long long result;

	scanf("%d", &N);

	result = Fibo(N);
	printf("%lld\n", result);

	return 0;
}