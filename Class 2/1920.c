/*
	1920번

	문제
	N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.
	
	입력
	첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다.
	다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다. 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다.
	모든 정수의 범위는 -231 보다 크거나 같고 231보다 작다.
	
	출력
	M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.

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