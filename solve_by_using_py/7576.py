from collections import deque

M, N = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

start = []
for x in range(N):
    for y in range(M):
        if graph[x][y] == 1:
            start.append((x, y))

def bfs(start):
    q = deque()

    for item in start:
        q.append(item)

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= N or ny >= M:
                continue
            if graph[nx][ny] == -1:
                continue
            elif graph[nx][ny] == 0:
                graph[nx][ny] = graph[x][y] + 1
                q.append((nx, ny))
    if any(0 in l for l in graph):
        return -1
    else:
        return max(map(max, graph)) - 1

print(bfs(start))
