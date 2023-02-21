import sys
from collections import deque
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

N, M = map(int, input().split())
x1, y1, x2, y2 = map(int, input().split())
classroom = [list(input().rstrip()) for _ in range(N)]

def bfs(x1, y1):
    global ans
    ans += 1
    visited = [[0] * M for _ in range(N)]
    q = deque()
    q.append((x1, y1))
    visited[x1][y1] = 1

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= N or ny >= M:
                continue
            if visited[nx][ny]:
                continue
            else:
                visited[nx][ny] = 1
            if classroom[nx][ny] == '1':
                classroom[nx][ny] = '0'
            elif classroom[nx][ny] == '0':
                q.append((nx, ny))
            elif classroom[nx][ny] == '#':
                return 1
    return 0

ans = 0
while 1:
    if bfs(x1 - 1, y1 - 1):
        break
print(ans)