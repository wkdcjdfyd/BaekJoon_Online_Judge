/*
	3052번

	문제
	두 자연수 A와 B가 있을 때, A%B는 A를 B로 나눈 나머지 이다. 예를 들어, 7, 14, 27, 38을 3으로 나눈 나머지는 1, 2, 0, 2이다. 
	수 10개를 입력받은 뒤, 이를 42로 나눈 나머지를 구한다. 그 다음 서로 다른 값이 몇 개 있는지 출력하는 프로그램을 작성하시오.

	입력
	첫째 줄부터 열번째 줄 까지 숫자가 한 줄에 하나씩 주어진다. 이 숫자는 1,000보다 작거나 같고, 음이 아닌 정수이다.

	출력
	첫째 줄에, 42로 나누었을 때, 서로 다른 나머지가 몇 개 있는지 출력한다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	int A = *(int *)a;
	int B = *(int *)b;

	if (A > B) {
		return 1;
	}
	else {
		return -1;
	}
}

int main() {
	int num[10];
	int i, temp;
	int count = 1;

	for (i = 0; i < 10; i++) {
		scanf("%d", &temp);
		num[i] = temp % 42;
	}

	qsort(num, 10, sizeof(int), compare);

	temp = num[0];

	for (i = 1; i < 10; i++) {
		if (temp != num[i]) {
			count++;
			temp = num[i];
		}
	}

	printf("%d\n", count);

	return 0;
}