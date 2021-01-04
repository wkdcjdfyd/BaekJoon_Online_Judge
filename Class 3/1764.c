/*
	1764��

	����
	�������� �赵 ���� ����� ��ܰ�, ���� ���� ����� ����� �־��� ��, �赵 ���� ���� ����� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

	�Է�
	ù° �ٿ� �赵 ���� ����� �� N, ���� ���� ����� �� M�� �־�����. �̾ ��° �ٺ��� N���� �ٿ� ���� �赵 ���� ����� �̸���,
	N+2° �ٺ��� ���� ���� ����� �̸��� ������� �־�����.
	�̸��� ���� ���� ���� �ҹ��ڷθ� �̷������, �� ���̴� 20 �����̴�. N, M�� 500,000 ������ �ڿ����̴�.
	�赵 ���� ����� ��ܿ��� �ߺ��Ǵ� �̸��� ������, ���� ���� ����� ��ܵ� ���������̴�.

	���
	�躸���� ���� �� ����� ���������� ����Ѵ�.

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