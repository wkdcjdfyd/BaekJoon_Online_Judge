/*
	10814��

	����
	�¶��� ������ ������ ������� ���̿� �̸��� ������ ������� �־�����. �̶�, ȸ������ ���̰� �����ϴ� ������,
	���̰� ������ ���� ������ ����� �տ� ���� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

	�Է�
	ù° �ٿ� �¶��� ���� ȸ���� �� N�� �־�����. (1 �� N �� 100,000)
	��° �ٺ��� N���� �ٿ��� �� ȸ���� ���̿� �̸��� �������� ���еǾ� �־�����. ���̴� 1���� ũ�ų� ������,
	200���� �۰ų� ���� �����̰�, �̸��� ���ĺ� ��ҹ��ڷ� �̷���� �ְ�, ���̰� 100���� �۰ų� ���� ���ڿ��̴�.
	�Է��� ������ ������ �־�����.

	���
	ù° �ٺ��� �� N���� �ٿ� ���� �¶��� ���� ȸ���� ���� ��, ���̰� ������ ������ ������ �� �ٿ� �� ��
	���̿� �̸��� �������� ������ ����Ѵ�.

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