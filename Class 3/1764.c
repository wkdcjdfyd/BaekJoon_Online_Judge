/*
	1764번

	문제
	김진영이 듣도 못한 사람의 명단과, 보도 못한 사람의 명단이 주어질 때, 듣도 보도 못한 사람의 명단을 구하는 프로그램을 작성하시오.

	입력
	첫째 줄에 듣도 못한 사람의 수 N, 보도 못한 사람의 수 M이 주어진다. 이어서 둘째 줄부터 N개의 줄에 걸쳐 듣도 못한 사람의 이름과,
	N+2째 줄부터 보도 못한 사람의 이름이 순서대로 주어진다.
	이름은 띄어쓰기 없이 영어 소문자로만 이루어지며, 그 길이는 20 이하이다. N, M은 500,000 이하의 자연수이다.
	듣도 못한 사람의 명단에는 중복되는 이름이 없으며, 보도 못한 사람의 명단도 마찬가지이다.

	출력
	듣보잡의 수와 그 명단을 사전순으로 출력한다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	char A[20];
	char B[20];

	strcpy(A, a);
	strcpy(B, b);
	
	int len_A = strlen(A);
	int len_B = strlen(B);

	if (len_A < len_B) {
		if (strncmp(A, B, len_A) == 0) {
			return -1;
		}
	}
	else {
		if (strncmp(A, B, len_B) == 0) {
			return 1;
		}
	}

	if (strcmp(A, B) > 0) {
		return 1;
	}
	else {
		return -1;
	}
}

int B_Search(char name[10000][20], char temp[20], int N) {
	int front = 0;
	int rear = N - 1;
	int mid;

	while (front < rear) {
		mid = (front + rear) / 2;
		if (strcmp(name[front], temp) == 0) {
			return 1;
		}
		if (strcmp(name[mid], temp) == 0) {
			return 1;
		}
		if (strcmp(name[rear], temp) == 0) {
			return 1;
		}
		if (strcmp(name[mid], temp) > 0) {
			rear = mid - 1;
		}
		else {
			front = mid + 1;
		}
	}
	return -1;
}

int main() {
	char name[500000][20];
	char result[500000][20];
	char temp[20];
	int N, M, i;
	int num;
	int j = 0;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) {
		scanf("%s", name[i]);
	}

	qsort(name, N, sizeof(name[0]), compare);

	for (i = 0; i < M; i++) {
		scanf("%s", temp);
		if (B_Search(name, temp, N) == 1) {
			strcpy(result[j], temp);
			j++;
		}
	}
	printf("%d\n", j);

	if (j != 0) {
		qsort(result, j, sizeof(result[0]), compare);

		for (i = 0; i < j; i++) {
			printf("%s\n", result[i]);
		}
	}

	return 0;
}