/*
	18870번

	문제
	수직선 위에 N개의 좌표 X1, X2, ..., XN이 있다. 이 좌표에 좌표 압축을 적용하려고 한다.
	Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표의 개수와 같아야 한다.
	X1, X2, ..., XN에 좌표 압축을 적용한 결과 X'1, X'2, ..., X'N를 출력해보자.

	입력
	첫째 줄에 N이 주어진다.
	둘째 줄에는 공백 한 칸으로 구분된 X1, X2, ..., XN이 주어진다.

	출력
	첫째 줄에 X'1, X'2, ..., X'N을 공백 한 칸으로 구분해서 출력한다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int index;
	int num;
	int new_num;
}node;

int compare1(const void *a, const void *b) {
	node A = *(node *)a;
	node B = *(node *)b;

	if (A.num > B.num) {
		return 1;
	}
	else {
		return -1;
	}
}

int compare2(const void *a, const void *b) {
	node A = *(node *)a;
	node B = *(node *)b;

	if (A.index > B.index) {
		return 1;
	}
	else {
		return -1;
	}
}


int main() {
	int n, i;
	int cnt = 1;
	node *arr;

	scanf("%d", &n);

	arr = (node *)malloc(sizeof(node) * n);

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i].num);
		arr[i].index = i;
	}
	qsort(arr, n, sizeof(node), compare1);

	arr[0].new_num = 0;
	for (i = 1; i < n; i++) {
		if (arr[i].num != arr[i - 1].num) {
			arr[i].new_num = cnt++;
		}
		else {
			arr[i].new_num = arr[i - 1].new_num;
		}
	}

	qsort(arr, n, sizeof(node), compare2);

	for (i = 0; i < n; i++) {
		printf("%d\n", arr[i].new_num);
	}

	free(arr);

	return 0;
}