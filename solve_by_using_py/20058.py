import sys
from collections import deque

input = sys.stdin.readline
dx = [-1, 1, 0, 0]
dy = [0, 0 ,-1, 1]

N, Q = map(int, input().split())
n = 2**N
graph = [list(map(int, input().split())) for _ in range(n)]
stage = list(map(int, input().split()))
visited = [[0] * n for _ in range(n)]


def rotate(arr):
    return [list(x) for x in zip(*arr[::-1])]


def is_near3ice(x, y):
    cnt = 0

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < n and graph[nx][ny] > 0:
            cnt += 1
    if cnt >= 3:
        return True
    else:
        return False


def bfs(a, b):
    q = deque()
    q.append((a, b))
    visited[a][b] = 1
    cnt = 1

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < n:
                if graph[nx][ny] > 0 and visited[nx][ny] == 0:
                    q.append((nx, ny))
                    visited[nx][ny] = 1
                    cnt += 1
    return cnt


for s in stage:
    jump = 2**s

    for x in range(0, n, jump):
        for y in range(0, n, jump):
            temp = []
            for x_list in graph[x:x+jump]:
                temp.append(x_list[y:y+jump])

            temp = rotate(temp)
            temp_x, temp_y = 0, 0

            for i in range(x, x+jump):
                temp_y = 0
                for j in range(y, y+jump):
                    graph[i][j] = temp[temp_x][temp_y]
                    temp_y += 1
                temp_x += 1


    q = deque()
    for x in range(n):
        for y in range(n):
            if not is_near3ice(x, y) and graph[x][y] > 0:
                q.append((x, y))
    while q:
        x, y  = q.popleft()
        graph[x][y] -= 1

ice_sum = 0
for x in graph:
    ice_sum += sum(x)

largest = 0
for x in range(n):
    for y in range(n):
        if graph[x][y] > 0 and visited[x][y] == 0:
            largest = max(largest, bfs(x, y))

print(ice_sum)
print(largest)
