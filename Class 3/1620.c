/*
	1620번

	문제
	

	입력
	첫째 줄에는 도감에 수록되어 있는 포켓몬의 개수 N이랑 내가 맞춰야 하는 문제의 개수 M이 주어져.
	N과 M은 1보다 크거나 같고, 100,000보다 작거나 같은 자연수인데, 자연수가 뭔지는 알지? 모르면 물어봐도 괜찮아.
	나는 언제든지 질문에 답해줄 준비가 되어있어.
	둘째 줄부터 N개의 줄에 포켓몬의 번호가 1번인 포켓몬부터 N번에 해당하는 포켓몬까지 한 줄에 하나씩 입력으로 들어와.
	포켓몬의 이름은 모두 영어로만 이루어져있고, 또, 음... 첫 글자만 대문자이고, 나머지 문자는 소문자로만 이루어져 있어.
	포켓몬 이름의 최대 길이는 20이야. 그 다음 줄부터 총 M개의 줄에 내가 맞춰야하는 문제가 입력으로 들어와.
	문제가 알파벳으로만 들어오면 포켓몬 번호를 말해야 하고, 숫자로만 들어오면, 포켓몬 번호에 해당하는 문자를 출력해야해.
	입력으로 들어오는 숫자는 반드시 1보다 크거나 같고, N보다 작거나 같고, 입력으로 들어오는 문자는 반드시 도감에 있는 포켓몬의 이름만 주어져.
	그럼 화이팅!!!

	출력
	첫째 줄부터 차례대로 M개의 줄에 각각의 문제에 대한 답을 말해줬으면 좋겠어!!!. 입력으로 숫자가 들어왔다면 그 숫자에 해당하는 포켓몬의 이름을,
	문자가 들어왔으면 그 포켓몬의 이름에 해당하는 번호를 출력하면 돼. 그럼 땡큐~

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pokemon {
	int num;
	char name[21];
}poke;

int compare1(const void *a, const void *b) {
	poke A = *(poke *)a;
	poke B = *(poke *)b;

	if (A.num > B.num) {
		return 1;
	}
	else {
		return -1;
	}
}

int compare2(const void *a, const void *b) {
	poke A = *(poke *)a;
	poke B = *(poke *)b;

	if (strcmp(A.name, B.name) > 0) {
		return 1;
	}
	else {
		return -1;
	}
}

void B_Search1(poke *P, int x, int N) {
	int front = 0;
	int rear = N - 1;
	int mid;
	while (front < rear) {
		mid = (front + rear) / 2;
		if (P[mid].num == x) {
			printf("%s\n", P[mid].name);
			return;
		}
		if (P[front].num == x) {
			printf("%s\n", P[front].name);
			return;
		}
		if (P[rear].num == x) {
			printf("%s\n", P[rear].name);
			return;
		}
		if (P[mid].num > x) {
			rear = mid - 1;
		}
		else {
			front = mid + 1;
		}
	}
}

void B_Search2(poke *P, char *x, int N) {
	int front = 0;
	int rear = N - 1;
	int mid;
	while (front < rear) {
		mid = (front + rear) / 2;
		if (strcmp(P[mid].name, x)==0) {
			printf("%d\n", P[mid].num);
			return;
		}
		if (strcmp(P[front].name, x) == 0) {
			printf("%d\n", P[front].num);
			return;
		}
		if (strcmp(P[rear].name, x) == 0) {
			printf("%d\n", P[rear].num);
			return;
		}
		if (strcmp(P[mid].name, x) > 0) {
			rear = mid - 1;
		}
		else {
			front = mid + 1;
		}
	}
}

int main() {
	int N, M, i;
	char temp[21];
	int temp_num;
	poke P1[100000];
	poke P2[100000];
	
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) {
		scanf("%s", temp);
		strcpy(P1[i].name, temp);
		strcpy(P2[i].name, temp);
		P1[i].num = i + 1;
		P2[i].num = i + 1;
	}

	qsort(P1, N, sizeof(poke), compare1);
	qsort(P2, N, sizeof(poke), compare2);

	for (i = 0; i < M; i++) {
		scanf("%s", temp);
		if (temp[0] >= '0' && temp[0] <= '9') {
			temp_num = atoi(temp);
			B_Search1(P1, temp_num, N);
		}
		else {
			B_Search2(P2, temp, N);
		}
	}

	return 0;
}