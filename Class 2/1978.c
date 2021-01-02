/*
	1978번

	문제
	주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.
	
	입력
	첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.

	출력
	주어진 수들 중 소수의 개수를 출력한다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int N, i, j;
	int *arr;
	int result = 0;

	scanf("%d", &N);
	arr = (int *)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		for (j = 2; j <= (int)sqrt(arr[i]); j++) {
			if (arr[i] % j == 0) {
				break;
			}
		}
		if (arr[i] != 1 && j == (int)sqrt(arr[i]) + 1) {
			result++;
		}
	}
	printf("%d\n", result);

	free(arr);

	return 0;
}