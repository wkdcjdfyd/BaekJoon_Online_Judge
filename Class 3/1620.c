/*
	1620��

	����
	

	�Է�
	ù° �ٿ��� ������ ���ϵǾ� �ִ� ���ϸ��� ���� N�̶� ���� ����� �ϴ� ������ ���� M�� �־���.
	N�� M�� 1���� ũ�ų� ����, 100,000���� �۰ų� ���� �ڿ����ε�, �ڿ����� ������ ����? �𸣸� ������� ������.
	���� �������� ������ ������ �غ� �Ǿ��־�.
	��° �ٺ��� N���� �ٿ� ���ϸ��� ��ȣ�� 1���� ���ϸ���� N���� �ش��ϴ� ���ϸ���� �� �ٿ� �ϳ��� �Է����� ����.
	���ϸ��� �̸��� ��� ����θ� �̷�����ְ�, ��, ��... ù ���ڸ� �빮���̰�, ������ ���ڴ� �ҹ��ڷθ� �̷���� �־�.
	���ϸ� �̸��� �ִ� ���̴� 20�̾�. �� ���� �ٺ��� �� M���� �ٿ� ���� ������ϴ� ������ �Է����� ����.
	������ ���ĺ����θ� ������ ���ϸ� ��ȣ�� ���ؾ� �ϰ�, ���ڷθ� ������, ���ϸ� ��ȣ�� �ش��ϴ� ���ڸ� ����ؾ���.
	�Է����� ������ ���ڴ� �ݵ�� 1���� ũ�ų� ����, N���� �۰ų� ����, �Է����� ������ ���ڴ� �ݵ�� ������ �ִ� ���ϸ��� �̸��� �־���.
	�׷� ȭ����!!!

	���
	ù° �ٺ��� ���ʴ�� M���� �ٿ� ������ ������ ���� ���� ���������� ���ھ�!!!. �Է����� ���ڰ� ���Դٸ� �� ���ڿ� �ش��ϴ� ���ϸ��� �̸���,
	���ڰ� �������� �� ���ϸ��� �̸��� �ش��ϴ� ��ȣ�� ����ϸ� ��. �׷� ��ť~

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pokemon {
	int num;
	char name[21];
}poke;

int compare1(const void *a, const void *b) {
	poke A = *(poke *)a;
	poke B = *(poke *)b;

	if (A.num > B.num) {
		return 1;
	}
	else {
		return -1;
	}
}

int compare2(const void *a, const void *b) {
	poke A = *(poke *)a;
	poke B = *(poke *)b;

	if (strcmp(A.name, B.name) > 0) {
		return 1;
	}
	else {
		return -1;
	}
}

void B_Search1(poke *P, int x, int N) {
	int front = 0;
	int rear = N - 1;
	int mid;
	while (front < rear) {
		mid = (front + rear) / 2;
		if (P[mid].num == x) {
			printf("%s\n", P[mid].name);
			return;
		}
		if (P[front].num == x) {
			printf("%s\n", P[front].name);
			return;
		}
		if (P[rear].num == x) {
			printf("%s\n", P[rear].name);
			return;
		}
		if (P[mid].num > x) {
			rear = mid - 1;
		}
		else {
			front = mid + 1;
		}
	}
}

void B_Search2(poke *P, char *x, int N) {
	int front = 0;
	int rear = N - 1;
	int mid;
	while (front < rear) {
		mid = (front + rear) / 2;
		if (strcmp(P[mid].name, x)==0) {
			printf("%d\n", P[mid].num);
			return;
		}
		if (strcmp(P[front].name, x) == 0) {
			printf("%d\n", P[front].num);
			return;
		}
		if (strcmp(P[rear].name, x) == 0) {
			printf("%d\n", P[rear].num);
			return;
		}
		if (strcmp(P[mid].name, x) > 0) {
			rear = mid - 1;
		}
		else {
			front = mid + 1;
		}
	}
}

int main() {
	int N, M, i;
	char temp[21];
	int temp_num;
	poke P1[100000];
	poke P2[100000];
	
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) {
		scanf("%s", temp);
		strcpy(P1[i].name, temp);
		strcpy(P2[i].name, temp);
		P1[i].num = i + 1;
		P2[i].num = i + 1;
	}

	qsort(P1, N, sizeof(poke), compare1);
	qsort(P2, N, sizeof(poke), compare2);

	for (i = 0; i < M; i++) {
		scanf("%s", temp);
		if (temp[0] >= '0' && temp[0] <= '9') {
			temp_num = atoi(temp);
			B_Search1(P1, temp_num, N);
		}
		else {
			B_Search2(P2, temp, N);
		}
	}

	return 0;
}