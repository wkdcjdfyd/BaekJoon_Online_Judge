/*
	9498번

	문제
	시험 점수를 입력받아 90 ~ 100점은 A, 80 ~ 89점은 B, 70 ~ 79점은 C, 60 ~ 69점은 D, 나머지 점수는 F를 출력하는 프로그램을 작성하시오.

	입력
	첫째 줄에 시험 점수가 주어진다. 시험 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.

	출력
	시험 성적을 출력한다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int score;

	scanf("%d", &score);

	if (score >= 90) {
		printf("A\n");
	}
	else if (score >= 80) {
		printf("B\n");
	}
	else if (score >= 70) {
		printf("C\n");
	}
	else if (score >= 60) {
		printf("D\n");
	}
	else {
		printf("F\n");
	}

	return 0;
}