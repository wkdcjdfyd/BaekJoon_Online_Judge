/*
	10816번

	문제
	정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

	명령은 총 다섯 가지이다.

	push X: 정수 X를 스택에 넣는 연산이다.
	pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	size: 스택에 들어있는 정수의 개수를 출력한다.
	empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
	top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

	입력
	첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다.
	주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

	출력
	출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.
	
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct Stack {
	int TOS;
	int arr[10000];
}stack;

void Push(stack *S, int x) {
	S->arr[++S->TOS] = x;
}

void Pop(stack *S) {
	if (S->TOS == -1) {
		printf("-1\n");
	}
	else {
		printf("%d\n", S->arr[S->TOS--]);
	}
}

void Size(stack *S) {
	printf("%d\n", S->TOS + 1);
}

void Empty(stack *S) {
	if (S->TOS > -1) {
		printf("0\n");
	}
	else {
		printf("1\n");
	}
}

void Top(stack *S) {
	if (S->TOS < 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", S->arr[S->TOS]);
	}
}

int main() {
	int N, i, temp;
	char order[10];
	stack S;
	S.TOS = -1;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%s", order);

		if (strcmp(order, "push") == 0) {
			scanf("%d", &temp);
			Push(&S, temp);
		}
		else if (strcmp(order, "pop") == 0) {
			Pop(&S);
		}
		else if (strcmp(order, "size") == 0) {
			Size(&S);
		}
		else if (strcmp(order, "empty") == 0) {
			Empty(&S);
		}
		else if (strcmp(order, "top") == 0) {
			Top(&S);
		}
	}

	return 0;
}