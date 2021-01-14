#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, Q;
int S;
long long *tree;
long long *num;

long long make_tree(int node, int left, int right) {
	if (left == right) {
		if (left <= N) {
			tree[node] = num[left];
			return tree[node];
		}
		else {
			tree[node] = 0;
			return tree[node];
		}
	}
	int mid = (left + right) / 2;
	tree[node] = make_tree(node * 2, left, mid);
	tree[node] += make_tree((node * 2) + 1, mid + 1, right);

	return tree[node];
}

long long query(int node, int left, int right, int qleft, int qright) {
	if (qright < left || right < qleft) {
		return 0;
	}
	else if (qleft <= left && right <= qright) {
		return tree[node];
	}
	else {
		int mid = (left + right) / 2;
		return query(node * 2, left, mid, qleft, qright) + query((node * 2) + 1, mid + 1, right, qleft, qright);
	}
}

void update(int node, int left, int right, int index, long long diff) {
	if (left <= index && index <= right) {
		tree[node] += diff;
		if (left != right) {
			int mid = (left + right) / 2;
			update(node * 2, left, mid, index, diff);
			update((node * 2) + 1, mid + 1, right, index, diff);
		}
	}
}

int main() {
	int i;
	int temp1, temp2, temp3;
	long long temp4, diff;

	scanf("%d %d", &N, &Q);

	num = (long long *)malloc(sizeof(long long) * (N + 1));

	for (i = 1; i < N + 1; i++) {
		scanf("%lld", &num[i]);
	}

	S = 1;
	while (S < N) {
		S *= 2;
	}

	tree = (long long *)malloc(sizeof(long long) * ((2 * S) + 1));

	make_tree(1, 1, S);

	for (i = 0; i < Q; i++) {
		scanf("%d %d %d %lld", &temp1, &temp2, &temp3, &temp4);
		if (temp1 > temp2) {
			printf("%lld\n", query(1, 1, S, temp2, temp1));
		}
		else {
			printf("%lld\n", query(1, 1, S, temp1, temp2));
		}

		diff = temp4 - num[temp3];
		num[temp3] = temp4;
		update(1, 1, S, temp3, diff);
	}

	free(num);
	free(tree);

	return 0;
}