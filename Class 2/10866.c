/*
	10866번

	문제
	정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
	
	명령은 총 여덟 가지이다.

	push_front X: 정수 X를 덱의 앞에 넣는다.
	push_back X: 정수 X를 덱의 뒤에 넣는다.
	pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	size: 덱에 들어있는 정수의 개수를 출력한다.
	empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
	front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

	입력
	첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다.
	주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.
	출력
	출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

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