#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Jew {
	int weight;
	int value;
}jew;

int compare1(const void *a, const void *b) {
	int A = *(int *)a;
	int B = *(int *)b;

	if (A > B) {
		return 1;
	}
	else {
		return -1;
	}
}

int compare2(const void *a, const void *b) {
	jew A = *(jew *)a;
	jew B = *(jew *)b;

	if (A.weight > B.weight) {
		return 1;
	}
	else {
		return -1;
	}
}

typedef struct HEAP {
	jew arr[300001];
	int size;
}heap;

void Insert(heap *H, jew x) {
	int i;


	for (i = ++H->size; i / 2 > 0 && H->arr[i / 2].value < x.value; i /= 2) {
		H->arr[i] = H->arr[i / 2];
	}
	H->arr[i] = x;
}

jew Delete(heap *H) {
	jew max, last;

	if (H->size == 0) {
		max.weight = 0;
		max.value = 0;
		return max;
	}
	int i, Child;
	max = H->arr[1];
	last = H->arr[H->size--];

	for (i = 1; i * 2 <= H->size; i = Child) {
		Child = i * 2;
		if (Child != H->size && H->arr[Child + 1].value > H->arr[Child].value) {
			Child++;
		}
		if (last.value < H->arr[Child].value) {
			H->arr[i] = H->arr[Child];
		}
		else {
			break;
		}
	}
	H->arr[i] = last;
	return max;
}

int main() {
	int N, K, i, j;
	long long result = 0;
	int bag[300001];
	jew J[300001];
	jew temp;
	heap H;
	H.size = 0;

	scanf("%d %d", &N, &K);

	for (i = 0; i < N; i++) {
		scanf("%d %d", &J[i].weight, &J[i].value);
	}

	qsort(J, N, sizeof(jew), compare2);

	for (i = 0; i < K; i++) {
		scanf("%d", &bag[i]);
	}

	qsort(bag, K, sizeof(int), compare1);

	j = 0;
	for (i = 0; i < K; i++) {
		for (; J[j].weight <= bag[i] && j < N; j++) {
			Insert(&H, J[j]);
		}
		temp = Delete(&H);
		result += temp.value;
	}

	printf("%lld\n", result);

	return 0;
}