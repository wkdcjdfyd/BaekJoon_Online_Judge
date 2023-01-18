import sys
input = sys.stdin.readline

N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]

for k in range(N):
    for a in range(N):
        for b in range(N):
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])

for i in range(M):
    A, B, C = map(int, input().split())
    if graph[A-1][B-1] > C:
        print('Stay here')
    else:
        print('Enjoy other party')
