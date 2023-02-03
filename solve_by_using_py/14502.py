import sys
from collections import deque
from copy import deepcopy
from itertools import combinations

input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs():
    q = deque()
    q.extend(virus)

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= N or ny >= M:
                continue
            if g[nx][ny] == 0:
                g[nx][ny] = 2
                q.append((nx, ny))

    num = 0
    for i in range(N):
        for j in range(M):
            if g[i][j] == 0:
                num += 1
    return num

N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
virus = []
wall = []

q = deque()

for i in range(N):
    for j in range(M):
        if graph[i][j] == 2:
            virus.append((i, j))
        elif graph[i][j] == 0:
            wall.append((i,j))

ans = -1000
for com in combinations(wall, 3):
    g = deepcopy(graph)
    for x, y in com:
        g[x][y] = 1

    ans = max(ans, bfs())

print(ans)
