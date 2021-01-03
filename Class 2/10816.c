/*
	10816번

	문제
	숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 정수 M개가 주어졌을 때,
	이 수가 적혀있는 숫자 카드를 상근이가 몇 개 가지고 있는지 구하는 프로그램을 작성하시오.

	입력
	첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다.
	숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.
	셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 몇 개 가지고 있는 숫자 카드인지 구해야 할 M개의 정수가 주어지며,
	이 수는 공백으로 구분되어져 있다. 이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.
	
	출력
	첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 몇 개 가지고 있는지를 공백으로 구분해 출력한다.

	참고 https://velog.io/@jsi06138/백준-10816번-숫자-카드2
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