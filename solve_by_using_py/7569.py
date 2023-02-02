from collections import deque

M, N, H = map(int, input().split())
graph = [list(list(map(int, input().split())) for _ in range(N)) for _ in range(H)]

dx = [1, -1, 0, 0, 0, 0]
dy = [0, 0, 1, -1, 0, 0]
dz = [0, 0, 0, 0, 1, -1]

q = deque()

for i in range(H):
    for j in range(N):
        for k in range(M):
            if graph[i][j][k] == 1:
                q.append((i, j, k))

while q:
    x, y, z = q.popleft()
    for idx in range(6):
        nx = x + dx[idx]
        ny = y + dy[idx]
        nz = z + dz[idx]
        if nx < 0 or ny < 0 or nz < 0 or nx >= H or ny >=N or nz >= M:
            continue
        if graph[nx][ny][nz] == 0:
            graph[nx][ny][nz] = graph[x][y][z] + 1
            q.append((nx, ny, nz))

result = -1
for h in graph:
    if any(0 in l for l in h):
        print(result)
        break
else:
    for h in graph:
        result = max(result, max(map(max, h)))
    print(result-1)
