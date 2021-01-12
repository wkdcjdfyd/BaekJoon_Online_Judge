#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, M;
long long arr[1000000];

long long wood(long long height) {
	long long sum = 0;
	int i;

	for (i = 0; i < N; i++) {
		if (arr[i] > height) {
			sum += (arr[i] - height);
		}
	}

	return sum;
}

long long B_Search() {
	long long front = 0;
	long long rear = arr[N - 1];
	long long mid;

	if (front == rear) {
		
	}

	while (front < rear) {
		mid = (front + rear) / 2;

		if (M > wood(mid)) {
			rear = mid;
		}
		else {
			front = mid + 1;
		}	
	}
	while (M > wood(mid)) {
		mid--;
	}

	return mid;
}

int compare(const void *a, const void *b) {
	long long A = *(long long *)a;
	long long B = *(long long *)b;

	if (A > B) {
		return 1;
	}
	else {
		return -1;
	}
}


int main() {
	int i;
	long long result;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}

	qsort(arr, N, sizeof(long long), compare);

	result = B_Search();

	printf("%lld\n", result);

	return 0;
}