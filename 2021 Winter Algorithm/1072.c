#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long x, y, z;

int B_Search() {
	int front = 0;
	int rear = 1000000001;
	int mid;
	long long temp;

	while (front < rear) {
		mid = (front + rear) / 2;
		temp = (100 * (y + mid)) / (x + mid);
		if (temp < z + 1) {
			front = mid + 1;
		}
		else {
			rear = mid;
		}
	}

	return front;
}

int main() {
	int a;

	scanf("%lld %lld", &x, &y);

	z = (100 * y) / x;

	if (z >= 99) {
		printf("-1\n");
	}
	else {
		a = B_Search();
		printf("%d\n", a);
	}

	return 0;
}