#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, step[310];
int max_point_1[310], max_point_2[310];

int getmax(int x, int y) {
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}

int main() {
	int i;

	scanf("%d", &n);

	for (i = 1; i < n + 1; i++) {
		scanf("%d", &step[i]);
	}
	max_point_1[1] = step[1];

	for (i = 2; i <= n; i++) {
		max_point_1[i] = getmax(max_point_1[i - 2], max_point_2[i - 2]) + step[i];
		max_point_2[i] = max_point_1[i - 1] + step[i];
	}

	printf("%d\n", getmax(max_point_1[n], max_point_2[n]));

	return 0;
}