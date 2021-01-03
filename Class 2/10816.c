/*
	10816��

	����
	���� ī��� ���� �ϳ��� ������ �ִ� ī���̴�. ����̴� ���� ī�� N���� ������ �ִ�. ���� M���� �־����� ��,
	�� ���� �����ִ� ���� ī�带 ����̰� �� �� ������ �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

	�Է�
	ù° �ٿ� ����̰� ������ �ִ� ���� ī���� ���� N(1 �� N �� 500,000)�� �־�����. ��° �ٿ��� ���� ī�忡 �����ִ� ������ �־�����.
	���� ī�忡 �����ִ� ���� -10,000,000���� ũ�ų� ����, 10,000,000���� �۰ų� ����.
	��° �ٿ��� M(1 �� M �� 500,000)�� �־�����. ��° �ٿ��� ����̰� �� �� ������ �ִ� ���� ī������ ���ؾ� �� M���� ������ �־�����,
	�� ���� �������� ���еǾ��� �ִ�. �� ���� -10,000,000���� ũ�ų� ����, 10,000,000���� �۰ų� ����.
	
	���
	ù° �ٿ� �Է����� �־��� M���� ���� ���ؼ�, �� ���� ���� ���� ī�带 ����̰� �� �� ������ �ִ����� �������� ������ ����Ѵ�.

	���� https://velog.io/@jsi06138/����-10816��-����-ī��2
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	int A = *(int *)a;
	int B = *(int *)b;

	if (A < B) {
		return -1;
	}
	else {
		return 1;
	}
}

int upper(int *arr, int x, int N) {
	int front = 0;
	int rear = N - 1;
	int mid;

	while (front < rear) {
		mid = (front + rear) / 2;
		if (arr[mid] <= x) {
			front = mid + 1;
		}
		else {
			rear = mid;
		}
	}
	if (arr[rear] != x) {
		rear--;
	}

	return rear;
}

int lower(int *arr, int x, int N) {
	int front = 0;
	int rear = N - 1;
	int mid;

	while (front < rear) {
		mid = (front + rear) / 2;
		if (arr[mid] < x) {
			front = mid + 1;
		}
		else {
			rear = mid;
		}
	}

	return rear;
}

int main() {
	int N, M, i, temp;
	int upidx, loidx;
	int *arr;

	scanf("%d", &N);
	arr = (int *)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, N, sizeof(int), compare);

	scanf("%d", &M);

	for (i = 0; i < M; i++) {
		scanf("%d", &temp);
		upidx = upper(arr,temp, N);
		loidx = lower(arr, temp, N);

		if (arr[loidx] == temp) {
			printf("%d\n", upidx - loidx + 1);
		}
		else {
			printf("0\n");
		}
	}

	free(arr);

	return 0;
}