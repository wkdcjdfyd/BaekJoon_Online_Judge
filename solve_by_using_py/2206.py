import sys
from collections import deque

input = sys.stdin.readline

dx = [-1, 1 ,0 ,0]
dy = [0, 0 ,-1 ,1]

N, M = map(int, input().split())
graph = [list(map(int, input().rstrip())) for _ in range(N)]
visited = [[[0] * 2 for _ in range(M)] for _ in range(N)]
flag = False

q = deque()
q.append((0, 0, 0))
visited[0][0][0] = 1

while q:
    x, y, z = q.popleft()
    if x == N-1 and y == M-1:
        print(visited[x][y][z])
        break
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or ny < 0 or nx >= N or ny >= M:
            continue
        if graph[nx][ny] == 1 and z == 0:
            visited[nx][ny][1] = visited[x][y][0] + 1
            q.append((nx,ny,1))
        elif graph[nx][ny] == 0 and visited[nx][ny][z] == 0:
            visited[nx][ny][z] = visited[x][y][z] + 1
            q.append((nx, ny, z))
else:
    print(-1)
