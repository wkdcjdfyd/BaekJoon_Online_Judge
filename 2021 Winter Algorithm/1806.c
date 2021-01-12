#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, S, i;
	int arr[100000];
	int front_idx, rear_idx, sum, len;
	int result = 100000;

	scanf("%d %d", &N, &S);

	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	front_idx = 0;
	rear_idx = 0;
	sum = arr[0];

	while (1) {
		if (sum >= S) {
			len = rear_idx - front_idx + 1;
			if (result > len) {
				result = len;
				if (len == 1) {
					break;
				}
			}
			if (front_idx != N) {
				sum -= arr[front_idx++];
			}
		}
		else {
			if (rear_idx != N) {
				sum += arr[++rear_idx];
			}
		}
		if (front_idx == N && rear_idx == N) {
			break;
		}
		if (rear_idx == N - 1 && sum < S) {
			break;
		}
	}

	if (result == 100000){
		result = 0;
	}

	printf("%d\n", result);

	return 0;
}