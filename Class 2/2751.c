/*
	2751��

	����
	N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

	�Է�
	ù° �ٿ� ���� ���� N(1 �� N �� 1,000,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���ڰ� �־�����.
	�� ���� ������ 1,000,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.
	
	���
	ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if (num1 < num2) {
		return -1;
	}
	else {
		return 1;
	}
}

int main() {
	int N, i;
	int *arr;

	scanf("%d", &N);

	arr = (int *)malloc(sizeof(int)*N);

	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, N, sizeof(int), compare);

	for (i = 0; i < N; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}