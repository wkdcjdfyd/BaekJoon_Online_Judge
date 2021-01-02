/*
	10814번

	문제
	온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주어진다. 이때, 회원들을 나이가 증가하는 순으로,
	나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 정렬하는 프로그램을 작성하시오.

	입력
	첫째 줄에 온라인 저지 회원의 수 N이 주어진다. (1 ≤ N ≤ 100,000)
	둘째 줄부터 N개의 줄에는 각 회원의 나이와 이름이 공백으로 구분되어 주어진다. 나이는 1보다 크거나 같으며,
	200보다 작거나 같은 정수이고, 이름은 알파벳 대소문자로 이루어져 있고, 길이가 100보다 작거나 같은 문자열이다.
	입력은 가입한 순서로 주어진다.

	출력
	첫째 줄부터 총 N개의 줄에 걸쳐 온라인 저지 회원을 나이 순, 나이가 같으면 가입한 순으로 한 줄에 한 명씩
	나이와 이름을 공백으로 구분해 출력한다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
	int age;
	char name[101];
	int order;
}person;

int compare(const void *a, const void *b) {
	person p1 = *(person *)a;
	person p2 = *(person *)b;

	if (p1.age > p2.age) {
		return 1;
	}
	else if (p1.age < p2.age) {
		return -1;
	}
	else {
		if (p1.order > p2.order) {
			return 1;
		}
		else {
			return -1;
		}
	}
}

int main() {
	int N, i;
	int tmp_age;
	char tmp_name[101];
	person *P;

	scanf("%d", &N);

	P = (person *)malloc(sizeof(person) * N);

	for (i = 0; i < N; i++) {
		scanf("%d %s", &tmp_age, tmp_name);
		P[i].age = tmp_age;
		P[i].order = i;
		strcpy(P[i].name, tmp_name);
	}

	qsort(P, N, sizeof(person), compare);

	for (i = 0; i < N; i++) {
		printf("%d %s\n", P[i].age, P[i].name);
	}

	free(P);

	return 0;
}