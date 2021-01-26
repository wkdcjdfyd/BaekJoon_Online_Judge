/*
	11724��

	����
	���� ���� �׷����� �־����� ��, ���� ��� (Connected Component)�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

	�Է�
	ù° �ٿ� ������ ���� N�� ������ ���� M�� �־�����. (1 �� N �� 1,000, 0 �� M �� N��(N-1)/2) ��° �ٺ���
	M���� �ٿ� ������ �� ���� u�� v�� �־�����. (1 �� u, v �� N, u �� v) ���� ������ �� ���� �־�����.

	���
	ù° �ٿ� ���� ����� ������ ����Ѵ�.

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