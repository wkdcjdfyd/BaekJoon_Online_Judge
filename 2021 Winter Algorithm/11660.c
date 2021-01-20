#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m, a[1034][1034];
int subsum[1034][1034];

int main() {
	int i, j, linesum, ans;
	int x1, x2;
	int y1, y2;

	scanf("%d %d", &n, &m);

	for (i = 1; i < n + 1; i++) {
		for (j = 1; j < n + 1; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for (i = 1; i < n + 1; i++) {
		linesum = 0;
		for (j = 1; j < n + 1; j++) {
			linesum += a[i][j];
			subsum[i][j] = subsum[i - 1][j] + linesum;
		}
	}

	for (i = 0; i < m; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		ans = subsum[x2][y2] - subsum[x2][y1 - 1] - subsum[x1 - 1][y2] + subsum[x1 - 1][y1 - 1];
		printf("%d\n", ans);
	}

	return 0;
}