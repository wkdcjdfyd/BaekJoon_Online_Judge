/*
	1978��

	����
	�־��� �� N�� �߿��� �Ҽ��� �� ������ ã�Ƽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	
	�Է�
	ù �ٿ� ���� ���� N�� �־�����. N�� 100�����̴�. �������� N���� ���� �־����µ� ���� 1,000 ������ �ڿ����̴�.

	���
	�־��� ���� �� �Ҽ��� ������ ����Ѵ�.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int N, i, j;
	int *arr;
	int result = 0;

	scanf("%d", &N);
	arr = (int *)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		for (j = 2; j <= (int)sqrt(arr[i]); j++) {
			if (arr[i] % j == 0) {
				break;
			}
		}
		if (arr[i] != 1 && j == (int)sqrt(arr[i]) + 1) {
			result++;
		}
	}
	printf("%d\n", result);

	free(arr);

	return 0;
}