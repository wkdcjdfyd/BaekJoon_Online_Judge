/*
	7568번

	문제
	우리는 사람의 덩치를 키와 몸무게, 이 두 개의 값으로 표현하여 그 등수를 매겨보려고 한다. 어떤 사람의 몸무게가
	x kg이고 키가 y cm라면 이 사람의 덩치는 (x,y)로 표시된다. 두 사람 A 와 B의 덩치가 각각 (x,y), (p,q)라고 할 때
	x>p 그리고 y>q 이라면 우리는 A의 덩치가 B의 덩치보다 "더 크다"고 말한다. 예를 들어 어떤 A, B 두 사람의 덩치가
	각각 (56,177), (45,165) 라고 한다면 A의 덩치가 B보다 큰 셈이 된다. 그런데 서로 다른 덩치끼리 크기를 정할 수
	없는 경우도 있다. 예를 들어 두 사람 C와 D의 덩치가 각각 (45, 181), (55,173)이라면 몸무게는 D가 C보다 더 무겁고,
	키는 C가 더 크므로, "덩치"로만 볼 때 C와 D는 누구도 상대방보다 더 크다고 말할 수 없다.

	N명의 집단에서 각 사람의 덩치 등수는 자신보다 더 "큰 덩치"의 사람의 수로 정해진다. 만일 자신보다 더 큰 덩치의
	사람이 k명이라면 그 사람의 덩치 등수는 k+1이 된다. 이렇게 등수를 결정하면 같은 덩치 등수를 가진 사람은 여러 명도
	가능하다. 아래는 5명으로 이루어진 집단에서 각 사람의 덩치와 그 등수가 표시된 표이다.

	입력
	첫 줄에는 전체 사람의 수 N이 주어진다. 그리고 이어지는 N개의 줄에는 각 사람의 몸무게와 키를 나타내는 양의 정수 x와 y가
	하나의 공백을 두고 각각 나타난다. 단, 2 ≤ N ≤ 50, 10 ≤ x,y ≤ 200 이다.

	출력
	여러분은 입력에 나열된 사람의 덩치 등수를 구해서 그 순서대로 첫 줄에 출력해야 한다. 단, 각 덩치 등수는 공백문자로 분리되어야 한다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Person {
	int weight;
	int height;
	int num;
}person;

int main() {
	int N, i, j;
	person *P;

	scanf("%d", &N);

	P = (person *)malloc(sizeof(person) * N);

	for (i = 0; i < N; i++) {
		scanf("%d %d", &P[i].weight, &P[i].height);
		P[i].num = 0;
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (i != j && P[i].weight < P[j].weight && P[i].height < P[j].height) {
				P[i].num++;
			}
		}
		printf("%d\n", (P[i].num) + 1);
	}

	free(P);

	return 0;
}