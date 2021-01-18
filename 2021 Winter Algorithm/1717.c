#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
int arr[1000010];

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


int main() {
	int cmd, a, b, i;

	scanf("%d %d", &n, &m);

	for (i = 0; i <= n; i++) {
		arr[i] = i;
	}
	
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &cmd, &a, &b);

		if (cmd == 0) {
			Union(a, b);
		}
		else if (cmd == 1) {
			if (Find(a) == Find(b)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}

	return 0;
}