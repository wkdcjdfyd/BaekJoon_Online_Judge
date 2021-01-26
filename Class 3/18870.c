/*
	18870��

	����
	������ ���� N���� ��ǥ X1, X2, ..., XN�� �ִ�. �� ��ǥ�� ��ǥ ������ �����Ϸ��� �Ѵ�.
	Xi�� ��ǥ ������ ��� X'i�� ���� Xi > Xj�� �����ϴ� ���� �ٸ� ��ǥ�� ������ ���ƾ� �Ѵ�.
	X1, X2, ..., XN�� ��ǥ ������ ������ ��� X'1, X'2, ..., X'N�� ����غ���.

	�Է�
	ù° �ٿ� N�� �־�����.
	��° �ٿ��� ���� �� ĭ���� ���е� X1, X2, ..., XN�� �־�����.

	���
	ù° �ٿ� X'1, X'2, ..., X'N�� ���� �� ĭ���� �����ؼ� ����Ѵ�.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int index;
	int num;
	int new_num;
}node;

int compare1(const void *a, const void *b) {
	node A = *(node *)a;
	node B = *(node *)b;

	if (A.num > B.num) {
		return 1;
	}
	else {
		return -1;
	}
}

int compare2(const void *a, const void *b) {
	node A = *(node *)a;
	node B = *(node *)b;

	if (A.index > B.index) {
		return 1;
	}
	else {
		return -1;
	}
}


int main() {
	int n, i;
	int cnt = 1;
	node *arr;

	scanf("%d", &n);

	arr = (node *)malloc(sizeof(node) * n);

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i].num);
		arr[i].index = i;
	}
	qsort(arr, n, sizeof(node), compare1);

	arr[0].new_num = 0;
	for (i = 1; i < n; i++) {
		if (arr[i].num != arr[i - 1].num) {
			arr[i].new_num = cnt++;
		}
		else {
			arr[i].new_num = arr[i - 1].new_num;
		}
	}

	qsort(arr, n, sizeof(node), compare2);

	for (i = 0; i < n; i++) {
		printf("%d\n", arr[i].new_num);
	}

	free(arr);

	return 0;
}