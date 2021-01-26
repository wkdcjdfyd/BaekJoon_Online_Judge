/*
	11724번

	문제
	방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

	입력
	첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터
	M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.

	출력
	첫째 줄에 연결 요소의 개수를 출력한다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

int v, e;
vector<int> graph[1001];
bool visited[1001];

void DFS(int v) {
	int i, next;

	visited[v] = true;

	for (i = 0; i < graph[v].size(); i++) {
		next = graph[v][i];
		if (!visited[next]) {
			DFS(next);
		}
	}
}

int main() {
	int i, v1, v2;
	int cnt = 0;

	scanf("%d %d", &v, &e);

	for (i = 0; i < e; i++) {
		scanf("%d %d", &v1, &v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	for (i = 1; i < v + 1; i++) {
		if (!visited[i]) {
			DFS(i);
			cnt++;
		}
	}
	printf("%d\n", cnt);

	return 0;
}