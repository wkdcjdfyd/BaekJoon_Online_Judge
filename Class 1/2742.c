/*
	2742번

	문제
	자연수 N이 주어졌을 때, 1부터 N까지 한 줄에 하나씩 출력하는 프로그램을 작성하시오.

	입력
	첫째 줄에 100,000보다 작거나 같은 자연수 N이 주어진다.

	출력
	첫째 줄부터 N번째 줄 까지 차례대로 출력한다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, i;

	scanf("%d", &N);

	for (i = N; i > 0; i--) {
		printf("%d\n", i);
	}

	return 0;
}