#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n, m;
int arr[1010];

typedef struct Edge {
	int x;
	int y;
	int cost;
}edge;

edge E[100010];

int Find(int x) {
	if (x == arr[x]) {
		return x;
	}
	arr[x] = Find(arr[x]);

	return arr[x];
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	arr[x] = y;
}

int compare(const void *a, const void *b) {
	edge A = *(edge *)a;
	edge B = *(edge *)b;

	if (A.cost > B.cost) {
		return 1;
	}
	else {
		return -1;
	}
}

int main() {
	int i;
	int result = 0;

	scanf("%d %d", &n, &m);

	for (i = 0; i <= n; i++) {
		arr[i] = i;
	}

	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &E[i].x, &E[i].y, &E[i].cost);
	}

	qsort(E, m, sizeof(edge), compare);

	for (i = 0; i < m; i++) {
		if (Find(E[i].x) != Find(E[i].y)) {
			Union(E[i].x, E[i].y);
			result += E[i].cost;
		}
	}

	printf("%d\n", result);

	return 0;
}