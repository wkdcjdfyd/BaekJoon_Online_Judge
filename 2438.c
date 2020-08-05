/*
	2438번

	문제
	첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제

	입력
	첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

	출력
	첫째 줄부터 N번째 줄까지 차례대로 별을 출력한다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int N, i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		for (j = 0; j < i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}