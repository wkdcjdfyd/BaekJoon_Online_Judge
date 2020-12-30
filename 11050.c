/*
	1259번

	문제
	자연수 과 정수 가 주어졌을 때 이항 계수를 구하는 프로그램을 작성하시오.

	입력
	첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 0 ≤ K ≤ N)

	출력
	nCk를 출력한다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int x, int n) {
	int i;
	int result = 1;

	for (i = 0; i < n; i++) {
		result = result * x;
		x--;
	}

	return result;
}

int main() {
	int N, K;

	scanf("%d %d", &N, &K);

	printf("%d\n", factorial(N, K) / factorial(K, K));

	return 0;
}