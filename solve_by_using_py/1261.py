from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

M, N = map(int, input().split())
graph = [list(map(int, input())) for _ in range(N)]
visited = [[-1]*M for _ in range(N)]

q = deque()
q.append((0,0))
visited[0][0] = 0

while q:
    x, y = q.popleft()
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or ny < 0 or nx >= N or ny >= M:
            continue
        if visited[nx][ny] == -1:
            if graph[nx][ny] == 0:
                q.appendleft((nx, ny))
                visited[nx][ny] = visited[x][y]
            else:
                q.append((nx, ny))
                visited[nx][ny] = visited[x][y] + 1

print(visited[N-1][M-1])
