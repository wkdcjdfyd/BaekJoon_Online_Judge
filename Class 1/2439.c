/*
	1546��

	����
	ù° �ٿ��� �� 1��, ��° �ٿ��� �� 2��, N��° �ٿ��� �� N���� ��� ����
	������, �������� �������� ������ ��(���� ����)�� ����Ͻÿ�.

	�Է�
	ù° �ٿ� N(1 �� N �� 100)�� �־�����.

	���
	ù° �ٺ��� N��° �ٱ��� ���ʴ�� ���� ����Ѵ�.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N;
	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		for (j = 0; j < N - i - 1; j++) {
			printf(" ");
		}
		for (j=i; j >= 0; j--) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}