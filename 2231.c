/*
	2231��

	����
	� �ڿ��� N�� ���� ��, �� �ڿ��� N�� �������� N�� N�� �̷�� �� �ڸ����� ���� �ǹ��Ѵ�.
	� �ڿ��� M�� �������� N�� ���, M�� N�� �����ڶ� �Ѵ�. ���� ���, 245�� �������� 256(=245+2+4+5)�� �ȴ�.
	���� 245�� 256�� �����ڰ� �ȴ�. ����, � �ڿ����� ��쿡�� �����ڰ� ���� ���� �ִ�.
	�ݴ��, �����ڰ� ���� ���� �ڿ����� ���� �� �ִ�.
	�ڿ��� N�� �־����� ��, N�� ���� ���� �����ڸ� ���س��� ���α׷��� �ۼ��Ͻÿ�.

	�Է�
	ù° �ٿ� �ڿ��� N(1 �� N �� 1,000,000)�� �־�����.

	���
	ù° �ٿ� ���� ����Ѵ�. �����ڰ� ���� ��쿡�� 0�� ����Ѵ�.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pow(int x, int y) {
	int i;
	int result = 1;

	if (y == 0) {
		return result;
	}

	for (i = 0; i < y; i++) {
		result = result * x;
	}

	return result;
}

int main() {
	int N;
	int i, j, temp, sum, y, z;
	int x = 0;

	scanf("%d", &N);
	temp = N;

	while (temp) {
		temp = temp / 10;
		x++;
	}

	for (i = N - (9 * x); i < N; i++) {
		temp = i;
		sum = 0;
		for (j = x; j > 0; j--) {
			y =  (pow(10, j - 1));
			z = temp / y;
			temp = temp - z * y;
			sum += z;
		}
		if (N == (i + sum)) {
			printf("%d\n", i);
			return 0;
		}
	}

	printf("0\n");

	return 0;
}