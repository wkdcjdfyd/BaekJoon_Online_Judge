#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
	int N, M, i;
	long long sum;
	int arr[100000];
	int front_idx, rear_idx;
	int cnt = 0;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) {
		scanf("%ld", &arr[i]);
	}

	front_idx = 0;
	rear_idx = 0;
	sum = arr[0];

	while (1) {
		if (sum < M) {
			if (rear_idx != N - 1) {
				sum += arr[++rear_idx];
			}
		}
		else if (sum == M) {
			cnt++;
			if (front_idx == rear_idx && rear_idx != N - 1) {
				sum += arr[++rear_idx];
			}
			else {
				if (front_idx != N) {
					sum -= arr[front_idx++];
				}
			}
		}
		else {
			if (front_idx == rear_idx && rear_idx != N - 1) {
				sum += arr[++rear_idx];
			}
			else if (front_idx != N) {
				sum -= arr[front_idx++];
			}
		}
		if (front_idx >= N-1 && rear_idx >= N-1) {
			if (sum == M) {
				cnt++;
			}
			break;
		}
		if (rear_idx == N-1 && sum < M) {
			break;
		}
	}

	printf("%d\n", cnt);

	return 0;
}