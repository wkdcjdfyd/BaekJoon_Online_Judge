#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct HEAP {
	int arr[100001];
	int size;
}heap;

void Insert(heap *H, int x) {
	int i;


	for (i = ++H->size; i/2 > 0 && H->arr[i / 2] < x; i /= 2) {
		H->arr[i] = H->arr[i / 2];
	}
	H->arr[i] = x;
}

void Delete(heap *H) {
	if (H->size == 0) {
		printf("0\n");
		return;
	}

	int i, Child;
	int max = H->arr[1];
	int last = H->arr[H->size--];

	for (i = 1; i * 2 <= H->size; i = Child) {
		Child = i * 2;
		if (Child != H->size && H->arr[Child + 1] > H->arr[Child]) {
			Child++;
		}
		if (last < H->arr[Child]) {
			H->arr[i] = H->arr[Child];
		}
		else {
			break;
		}
	}
	H->arr[i] = last;
	printf("%d\n", max);
	return;
}

int main() {
	int N, i, temp;
	heap H;
	H.size = 0;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &temp);

		if (temp == 0) {
			Delete(&H);
		}
		else {
			Insert(&H, temp);
		}
	}
	return 0;
}