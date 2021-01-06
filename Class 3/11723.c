/*
	11723��

	����
	����ִ� ������ S�� �־����� ��, �Ʒ� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

	add x: S�� x�� �߰��Ѵ�. (1 �� x �� 20) S�� x�� �̹� �ִ� ��쿡�� ������ �����Ѵ�.
	remove x: S���� x�� �����Ѵ�. (1 �� x �� 20) S�� x�� ���� ��쿡�� ������ �����Ѵ�.
	check x: S�� x�� ������ 1��, ������ 0�� ����Ѵ�. (1 �� x �� 20)
	toggle x: S�� x�� ������ x�� �����ϰ�, ������ x�� �߰��Ѵ�. (1 �� x �� 20)
	all: S�� {1, 2, ..., 20} ���� �ٲ۴�.
	empty: S�� ���������� �ٲ۴�. 

	�Է�
	ù° �ٿ� �����ؾ� �ϴ� ������ �� M (1 �� M �� 3,000,000)�� �־�����.
	��° �ٺ��� M���� �ٿ� �����ؾ� �ϴ� ������ �� �ٿ� �ϳ��� �־�����.

	���
	check ������ �־���������, ����� ����Ѵ�.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int S_num;

int Check(int *S, int x) {
	int i;

	for (i = 0; i < S_num; i++) {
		if (S[i] == x) {
			return 1;
		}
	}
	return 0;
}

void Add(int *S, int x) {
	if (Check(S, x)) {
		return;
	}
	S[S_num++] = x;
}

void Remove(int *S, int x) {
	int i;

	for (i = 0; i < S_num; i++) {
		if (S[i] == x) {
			S[i] = S[S_num - 1];
			S_num--;
		}
	}
}

void Toggle(int *S, int x) {
	if (Check(S, x)) {
		Remove(S, x);
	}
	else {
		Add(S, x);
	}
}

void All(int *S) {
	int i;
	S_num = 20;

	for (i = 0; i < S_num; i++) {
		S[i] = i + 1;
	}
}

void Empty() {
	S_num = 0;
}

int main() {
	int S[20];
	int M, i, temp;
	char order[15];

	scanf("%d", &M);

	S_num = 0;
	for (i = 0; i < M; i++) {
		scanf("%s", order);

		if (strcmp(order, "add") == 0) {
			scanf("%d", &temp);
			Add(S, temp);
		}
		else if (strcmp(order, "remove") == 0) {
			scanf("%d", &temp);
			Remove(S, temp);
		}
		else if (strcmp(order, "check") == 0) {
			scanf("%d", &temp);
			printf("%d\n", Check(S, temp));
		}
		else if (strcmp(order, "toggle") == 0) {
			scanf("%d", &temp);
			Toggle(S, temp);
		}
		else if (strcmp(order, "all") == 0) {
			All(S);
		}
		else if (strcmp(order, "empty") == 0) {
			Empty();
		}
	}

	return 0;
}