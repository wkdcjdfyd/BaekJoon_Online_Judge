/*
	1181번

	문제
	알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.

	1. 길이가 짧은 것부터
	2. 길이가 같으면 사전 순으로

	입력
	첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다.
	주어지는 문자열의 길이는 50을 넘지 않는다.

	출력
	조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word {
	char str[51];
	int len;
}word;

int compare(const void *a, const void *b) {
	word tmp1 = *(word *)a;
	word tmp2 = *(word *)b;

	if (tmp1.len != tmp2.len) {
		return (tmp1.len - tmp2.len);
	}
	return strcmp(tmp1.str, tmp2.str);
}

int main() {
	int N, i;
	word *w;

	scanf("%d", &N);

	w = (word *)malloc(sizeof(word) * N);

	for (i = 0; i < N; i++) {
		scanf("%s", &w[i].str);
		w[i].len = strlen(w[i].str);
	}


	qsort(w, N, sizeof(word), compare);

	for (i = 0; i < N; i++) {
		if (strcmp(w[i].str, w[i + 1].str) != 0) {
			printf("%s\n", w[i].str);
		}
	}

	free(w);

	return 0;
}