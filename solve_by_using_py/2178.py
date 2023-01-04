from collections import deque

N, M = map(int, input().split())
graph = []

for _ in range(N):
    data = list(input())
    graph.append(list(map(int, data)))

dx = [-1, 1, 0 ,0]
dy = [0, 0, -1, 1]

def bfs(a, b):
    q = deque()
    q.append((a, b))

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= N or ny >= M:
                continue
            if graph[nx][ny] != 1:
                continue
            graph[nx][ny] = graph[x][y] + 1
            q.append((nx, ny))

bfs(0, 0)
print(graph[N-1][M-1])
