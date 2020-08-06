/*
	2920번

	문제
	다장조는 c d e f g a b C, 총 8개 음으로 이루어져있다.
	이 문제에서 8개 음은 다음과 같이 숫자로 바꾸어 표현한다. c는 1로, d는 2로, ..., C를 8로 바꾼다.
	1부터 8까지 차례대로 연주한다면 ascending, 8부터 1까지 차례대로 연주한다면 descending,
	둘 다 아니라면 mixed 이다. 연주한 순서가 주어졌을 때, 이것이 ascending인지, descending인지,
	아니면 mixed인지 판별하는 프로그램을 작성하시오.

	입력
	첫째 줄에 8개 숫자가 주어진다. 이 숫자는 문제 설명에서 설명한 음이며, 1부터 8까지 숫자가 한 번씩 등장한다.

	출력
	첫째 줄에 ascending, descending, mixed 중 하나를 출력한다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main() {
	char S[20];

	gets(S);

	if (strcmp(S,"1 2 3 4 5 6 7 8") == 0) {
		printf("ascending\n");
	}
	else if (strcmp(S, "8 7 6 5 4 3 2 1") == 0) {
		printf("descending\n");
	}
	else {
		printf("mixed\n");
	}

	return 0;
}