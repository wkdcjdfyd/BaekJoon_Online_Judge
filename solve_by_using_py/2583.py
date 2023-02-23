from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

M, N, K = map(int, input().split())
graph = [[-1] * N for _ in range(M)]
visited = [[0] * N for _ in range(M)]

for _ in range(K):
    x1, y1, x2, y2 = map(int, input().split())

    for i in range(y1, y2):
        for j in range(x1, x2):
            graph[i][j] = 0

def bfs(a, b):
    q = deque()
    q.append((a, b))
    cnt = 1
    visited[a][b] = cnt

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or ny < 0 or nx >= M or ny >= N:
                continue
            if visited[nx][ny] != 0:
                continue
            if graph[nx][ny] == -1:
                cnt += 1
                visited[nx][ny] = cnt
                q.append((nx, ny))
    return cnt

cnt = 0
result = []
for i in range(M):
    for j in range(N):
        if visited[i][j] ==0 and graph[i][j] == -1:
            cnt += 1
            result.append(bfs(i, j))
result.sort()

print(cnt)
print(*result)
