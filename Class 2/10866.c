/*
	10866��

	����
	������ �����ϴ� ��(Deque)�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	
	����� �� ���� �����̴�.

	push_front X: ���� X�� ���� �տ� �ִ´�.
	push_back X: ���� X�� ���� �ڿ� �ִ´�.
	pop_front: ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
	pop_back: ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
	size: ���� ����ִ� ������ ������ ����Ѵ�.
	empty: ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
	front: ���� ���� �տ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
	back: ���� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

	�Է�
	ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����.
	�־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.
	���
	����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node node;

struct Node {
	int num;
	node *next;
	node *prev;
};

void Push_Front(node *head, node *tail, int x) {
	node *temp = (node *)malloc(sizeof(node));
	temp->num = x;
	temp->prev = NULL;
	temp->next = head->next;
	if (head->next != NULL) {
		temp->next->prev = temp;
	}
	head->next = temp;
	if (tail->prev == NULL) {
		tail->prev = temp;
	}
}

void Push_Back(node *head, node *tail, int x) {
	node *temp = (node *)malloc(sizeof(node));
	temp->num = x;
	temp->next = NULL;
	temp->prev = tail->prev;
	if (tail->prev != NULL) {
		tail->prev->next = temp;
	}
	tail->prev = temp;
	if (head->next == NULL) {
		head->next = temp;
	}
}

void Pop_Front(node *head, node *tail) {
	node *temp;
	if (head->next == NULL) {
		printf("-1\n");
	}
	else {
		printf("%d\n", head->next->num);
		temp = head->next;
		head->next = head->next->next;
		if (head->next != NULL) {
			head->next->prev = NULL;
		}
		free(temp);
		if (head->next == NULL) {
			tail->prev = NULL;
		}
	}
}

void Pop_Back(node *head, node *tail) {
	node *temp;
	if (tail->prev == NULL) {
		printf("-1\n");
	}
	else {
		printf("%d\n", tail->prev->num);
		temp = tail->prev;
		tail->prev = tail->prev->prev;
		if (tail->prev != NULL) {
			tail->prev->next = NULL;
		}
		free(temp);
		if (tail->prev == NULL) {
			head->next = NULL;
		}
	}
}

void Size(node *head) {
	int cnt = 0;
	node *temp = head->next;

	while (temp != NULL) {
		temp = temp->next;
		cnt++;
	}
	printf("%d\n", cnt);
}

void Empty(node *head) {
	if (head->next == NULL) {
		printf("1\n");
	}
	else {
		printf("0\n");
	}
}

void Front(node *head) {
	if (head->next == NULL) {
		printf("-1\n");
	}
	else {
		printf("%d\n", head->next->num);
	}
}

void Back(node *tail) {
	if (tail->prev == NULL) {
		printf("-1\n");
	}
	else {
		printf("%d\n", tail->prev->num);
	}
}

int main() {
	int N, i, temp;
	char order[15];
	node *head = (node *)malloc(sizeof(node));
	node *tail = (node *)malloc(sizeof(node));
	head->next = NULL;
	head->prev = NULL;
	tail->next = NULL;
	tail->prev = NULL;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%s", order);

		if (strcmp(order, "push_front") == 0) {
			scanf("%d", &temp);
			Push_Front(head, tail, temp);
		}
		else if (strcmp(order, "push_back") == 0) {
			scanf("%d", &temp);
			Push_Back(head, tail, temp);
		}
		else if (strcmp(order, "pop_front") == 0) {
			Pop_Front(head, tail);
		}
		else if (strcmp(order, "pop_back") == 0) {
			Pop_Back(head, tail);
		}
		else if (strcmp(order, "size") == 0) {
			Size(head);
		}
		else if (strcmp(order, "empty") == 0) {
			Empty(head);
		}
		else if (strcmp(order, "front") == 0) {
			Front(head);
		}
		else if (strcmp(order, "back") == 0) {
			Back(tail);
		}
	}

	return 0;
}