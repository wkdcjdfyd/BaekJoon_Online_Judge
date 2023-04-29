from copy import deepcopy
from collections import deque

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

N, M, K = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]

def move_dice(d):
    temp = deepcopy(dice)
    # 동
    if d == 0:
        temp[0] = dice[4]
        temp[2] = dice[5]
        temp[4] = dice[2]
        temp[5] = dice[0]
    # 남
    elif d == 1:
        temp[1] = dice[4]
        temp[3] = dice[5]
        temp[4] = dice[3]
        temp[5] = dice[1]
    # 서
    elif d == 2:
        temp[0] = dice[5]
        temp[2] = dice[4]
        temp[4] = dice[0]
        temp[5] = dice[2]
    # 북
    elif d == 3:
        temp[1] = dice[5]
        temp[3] = dice[4]
        temp[4] = dice[1]
        temp[5] = dice[3]

    return temp


def bfs(a, b):
    q = deque()
    q.append((a, b))
    visited = [[0] * M for _ in range(N)]
    visited[a][b] = 1
    num = 1

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < N and 0 <= ny < M:
                if visited[nx][ny] == 0 and graph[a][b] == graph[nx][ny]:
                    num += 1
                    visited[nx][ny] = 1
                    q.append((nx, ny))

    return num

# 동, 남, 서, 북, 위, 아래
dice = [3, 5, 4, 2, 1, 6]
x, y, d = 0, 0, 0
score = 0

for n in range(K):
    nx = x + dx[d]
    ny = y + dy[d]

    if nx < 0 or ny < 0 or nx >= N or ny >= M:
        d = (d+2) % 4
        nx = x + dx[d]
        ny = y + dy[d]
    dice = move_dice(d)

    cnt = bfs(nx, ny)
    score += graph[nx][ny] * cnt

    if dice[-1] > graph[nx][ny]:
        d = (d+1) % 4
    elif dice[-1] < graph[nx][ny]:
        d = (d-1) % 4
    x = nx
    y = ny

print(score)
