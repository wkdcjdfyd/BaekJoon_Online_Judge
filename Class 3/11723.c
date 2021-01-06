/*
	11723번

	문제
	비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.

	add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
	remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
	check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
	toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
	all: S를 {1, 2, ..., 20} 으로 바꾼다.
	empty: S를 공집합으로 바꾼다. 

	입력
	첫째 줄에 수행해야 하는 연산의 수 M (1 ≤ M ≤ 3,000,000)이 주어진다.
	둘째 줄부터 M개의 줄에 수행해야 하는 연산이 한 줄에 하나씩 주어진다.

	출력
	check 연산이 주어질때마다, 결과를 출력한다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int S_num;

int Check(int *S, int x) {
	int i;

	for (i = 0; i < S_num; i++) {
		if (S[i] == x) {
			return 1;
		}
	}
	return 0;
}

void Add(int *S, int x) {
	if (Check(S, x)) {
		return;
	}
	S[S_num++] = x;
}

void Remove(int *S, int x) {
	int i;

	for (i = 0; i < S_num; i++) {
		if (S[i] == x) {
			S[i] = S[S_num - 1];
			S_num--;
		}
	}
}

void Toggle(int *S, int x) {
	if (Check(S, x)) {
		Remove(S, x);
	}
	else {
		Add(S, x);
	}
}

void All(int *S) {
	int i;
	S_num = 20;

	for (i = 0; i < S_num; i++) {
		S[i] = i + 1;
	}
}

void Empty() {
	S_num = 0;
}

int main() {
	int S[20];
	int M, i, temp;
	char order[15];

	scanf("%d", &M);

	S_num = 0;
	for (i = 0; i < M; i++) {
		scanf("%s", order);

		if (strcmp(order, "add") == 0) {
			scanf("%d", &temp);
			Add(S, temp);
		}
		else if (strcmp(order, "remove") == 0) {
			scanf("%d", &temp);
			Remove(S, temp);
		}
		else if (strcmp(order, "check") == 0) {
			scanf("%d", &temp);
			printf("%d\n", Check(S, temp));
		}
		else if (strcmp(order, "toggle") == 0) {
			scanf("%d", &temp);
			Toggle(S, temp);
		}
		else if (strcmp(order, "all") == 0) {
			All(S);
		}
		else if (strcmp(order, "empty") == 0) {
			Empty();
		}
	}

	return 0;
}