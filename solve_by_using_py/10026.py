import sys
from collections import deque
from copy import deepcopy

COLOR = ['R', 'G', 'B']

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

input = sys.stdin.readline

N = int(input())
graph = [list(input().rstrip()) for _ in range(N)]

def bfs(start, is_sick, num):
    q = deque()
    q.append(start)
    color = g[start[0]][start[1]]

    if color == 'R' or color == 'G':
        if is_sick:
            color = ['R', 'G']
        else:
            color = [color]
    else:
        color = ['B']

    g[start[0]][start[1]] = num

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= N or ny >= N:
                continue
            if g[nx][ny] in color:
                g[nx][ny] = num
                q.append((nx, ny))

ans = []
for sick in [False, True]:
    g = deepcopy(graph)
    num = 0
    for i in range(N):
        for j in range(N):
            if g[i][j] in COLOR:
                num += 1
                bfs((i, j), sick, num)
    ans.append(num)

print(ans[0], ans[1])
