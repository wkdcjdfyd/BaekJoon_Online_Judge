from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

N = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]
min_height = 100
max_height = 1

for i in range(N):
    for j in range(N):
        if graph[i][j] < min_height:
            min_height = graph[i][j]
        if graph[i][j] > max_height:
            max_height = graph[i][j]

def bfs(i, j, cnt, h, visited):
    q = deque()
    q.append((i, j))
    visited[i][j] = cnt

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= N or ny >= N:
                continue
            if visited[nx][ny] != 0:
                continue
            if graph[nx][ny] > h:
                visited[nx][ny] = cnt
                q.append((nx, ny))

ans = -1
for height in range(min_height, max_height):
    visited = [[0] * N for _ in range(N)]
    cnt = 0

    for i in range(N):
        for j in range(N):
            if graph[i][j] > height and visited[i][j] == 0:
                cnt += 1
                bfs(i, j, cnt, height, visited)

    if ans < cnt:
        ans = cnt

print(ans) if ans != -1 else print(1)
