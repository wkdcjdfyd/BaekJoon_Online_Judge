/*
	1259��

	����
	�ڿ��� �� ���� �� �־����� �� ���� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

	�Է�
	ù° �ٿ� N�� K�� �־�����. (1 �� N �� 10, 0 �� K �� N)

	���
	nCk�� ����Ѵ�.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int x, int n) {
	int i;
	int result = 1;

	for (i = 0; i < n; i++) {
		result = result * x;
		x--;
	}

	return result;
}

int main() {
	int N, K;

	scanf("%d %d", &N, &K);

	printf("%d\n", factorial(N, K) / factorial(K, K));

	return 0;
}