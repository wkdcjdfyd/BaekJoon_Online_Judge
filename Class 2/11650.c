/*
	11650��

	����
	2���� ��� ���� �� N���� �־�����. ��ǥ�� x��ǥ�� �����ϴ� ������, x��ǥ�� ������ y��ǥ�� �����ϴ� ������ ������ ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	
	�Է�
	ù° �ٿ� ���� ���� N (1 �� N �� 100,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� i������ ��ġ xi�� yi�� �־�����. (-100,000 �� xi, yi �� 100,000) ��ǥ�� �׻� �����̰�, ��ġ�� ���� �� ���� ����.

	���
	ù° �ٺ��� N���� �ٿ� ���� ������ ����� ����Ѵ�.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Plain {
	int x;
	int y;
} plain;

int compare(const void *a, const void *b) {
	plain A = *(plain *)a;
	plain B = *(plain *)b;

	if (A.x > B.x) {
		return 1;
	}
	else if (A.x < B.x) {
		return -1;
	}
	else {
		if (A.y > B.y) {
			return 1;
		}
		else {
			return -1;
		}
	}
}

int main() {
	int N, i;
	plain *P;

	scanf("%d", &N);

	P = (plain *)malloc(sizeof(plain) * N);

	for (i = 0; i < N; i++) {
		scanf("%d %d", &P[i].x, &P[i].y);
	}

	qsort(P, N, sizeof(plain), compare);

	for (i = 0; i < N; i++) {
		printf("%d %d\n", P[i].x, P[i].y);
	}

	free(P);

	return 0;
}