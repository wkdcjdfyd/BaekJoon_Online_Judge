import sys
from collections import deque

input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]

def water_counter(a, b):
    cnt = 0
    for i in range(4):
        na = a + dx[i]
        nb = b + dy[i]
        if 0 <= na < N and 0 <= nb < M:
            if graph[na][nb] == 0:
                cnt += 1
    return cnt


def bfs(a, b, arr, num):
    q = deque()
    q.append((a, b))
    arr[a][b] = num

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 > nx or 0 > ny or nx >= N or ny >= M:
                continue
            if graph[nx][ny] != 0 and arr[nx][ny] == 0:
                arr[nx][ny] = num
                q.append((nx, ny))


def iceberg_counter():
    arr = [[0] * M for _ in range(N)]
    cnt = 0

    for i in range(N):
        for j in range(M):
            if graph[i][j] != 0 and arr[i][j] == 0:
                cnt += 1
                bfs(i, j, arr, cnt)
    return cnt

year = 0
while 1:
    cnt = iceberg_counter()
    if cnt == 0:
        print(0)
        break
    elif cnt > 1:
        print(year)
        break
    else:
        q = deque()
        for i in range(N):
            for j in range(M):
                if graph[i][j] != 0:
                    q.append((i, j, water_counter(i, j)))
        while q:
            i, j, num = q.popleft()
            if graph[i][j] - num < 0:
                graph[i][j] = 0
            else:
                graph[i][j] -= num
    year += 1