from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
ans = 0

while 1:
    visited = [[0 for _ in range(M)] for _ in range(N)]
    q = deque()
    q.append((0, 0))
    visited[0][0] = 1

    while q:
        x, y= q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= N or ny >= M:
                continue
            if visited[nx][ny] == 0:
                if graph[nx][ny] > 0:
                    graph[nx][ny] += 1
                else:
                    visited[nx][ny] = 1
                    q.append((nx, ny))

    is_ch = 0
    for i in range(N):
        for j in range(M):
            if graph[i][j] >= 3:
                graph[i][j] = 0
            elif graph[i][j] > 0:
                graph[i][j] = 1
                is_ch = 1
    ans += 1

    if not is_ch:
        break
print(ans)
