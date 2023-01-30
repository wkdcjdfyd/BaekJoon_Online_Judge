import sys
from collections import deque

input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

N = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]
visited = [[False] * N for _ in range(N)]
cnt = 1
ans = sys.maxsize

def grouping(x, y):
    global cnt
    q = deque()
    q.append((x, y))
    visited[x][y] = True
    graph[x][y] = cnt

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= N or ny >= N:
                continue
            if graph[nx][ny] == 1 and not visited[nx][ny]:
                visited[nx][ny] = True
                graph[nx][ny] = cnt
                q.append((nx, ny))


def bfs(island):
    global ans
    dist = [[-1] * N for _ in range(N)]
    q = deque()

    for i in range(N):
        for j in range(N):
            if graph[i][j] == island:
                q.append((i, j))
                dist[i][j] = 0

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= N or ny >= N:
                continue
            if graph[nx][ny] > 0 and graph[nx][ny] != island:
                ans = dist[x][y] if ans > dist[x][y] else ans
                return
            if graph[nx][ny] == 0 and dist[nx][ny] == -1:
                dist[nx][ny] = dist[x][y] + 1
                q.append((nx, ny))


for i in range(N):
    for j in range(N):
        if graph[i][j] == 1 and not visited[i][j]:
            grouping(i, j)
            cnt += 1

for island in range(1, cnt):
    bfs(island)

print(ans)
