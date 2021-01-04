/*
	10816��

	����
	������ �����ϴ� ������ ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

	����� �� �ټ� �����̴�.

	push X: ���� X�� ���ÿ� �ִ� �����̴�.
	pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
	size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
	empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
	top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

	�Է�
	ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����.
	�־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

	���
	����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.
	
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