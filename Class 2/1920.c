/*
	1920��

	����
	N���� ���� A[1], A[2], ��, A[N]�� �־��� ���� ��, �� �ȿ� X��� ������ �����ϴ��� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.
	
	�Է�
	ù° �ٿ� �ڿ��� N(1 �� N �� 100,000)�� �־�����. ���� �ٿ��� N���� ���� A[1], A[2], ��, A[N]�� �־�����.
	���� �ٿ��� M(1 �� M �� 100,000)�� �־�����. ���� �ٿ��� M���� ������ �־����µ�, �� ������ A�ȿ� �����ϴ��� �˾Ƴ��� �ȴ�.
	��� ������ ������ -231 ���� ũ�ų� ���� 231���� �۴�.
	
	���
	M���� �ٿ� ���� ����Ѵ�. �����ϸ� 1��, �������� ������ 0�� ����Ѵ�.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	int A = *(int *)a;
	int B = *(int *)b;

	if (A > B) {
		return 1;
	}
	else {
		return -1;
	}
}

int B_Search(int *arr, int x, int len) {
	int front = 0;
	int rear = len - 1;
	int mid;

	while (1) {
		mid = (front + rear) / 2;
		if (arr[front] == x || arr[rear] == x || arr[mid] == x) {
			return 1;
		}
		if (arr[mid] < x) {
			front = mid + 1;
		}
		else {
			rear = mid - 1;
		}
		if (rear < front) {
			return 0;
		}
	}
}

int main() {
	int N, M, i, j, B;
	int *A;
	int result;

	scanf("%d", &N);
	A = (int *)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	qsort(A, N, sizeof(int), compare);

	scanf("%d", &M);

	for (i = 0; i < M; i++) {
		scanf("%d", &B);
		result = B_Search(A, B, N);
		printf("%d\n", result);
	}

	free(A);

	return 0;
}