from copy import deepcopy
from math import floor

dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]

tornado = [[0, 0, 0.02, 0, 0],
           [0, 0.1, 0.07, 0.01, 0],
           [0.05, 0, 0, 0, 0],
           [0, 0.1, 0.07, 0.01, 0],
           [0, 0, 0.02, 0, 0]]

N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]
x, y = N // 2, N // 2
move_cnt = 0
move_scale = 1
d = 0
ans = 0


def rotate(origin):
    reversed_ = origin[::-1]
    return list(zip(*reversed_))


def move_sand(a, b, d, arr):
    global ans

    alpha = arr[a][b]
    t = deepcopy(tornado)

    if d == 1:
        for i in range(3):
            t = rotate(t)
    elif d == 2:
        for i in range(2):
            t = rotate(t)
    elif d == 3:
        t = rotate(t)

    for i in range(-2, 3):
        na = a + i
        for j in range(-2, 3):
            nb = b + j
            if 0 <= na < N and 0 <= nb <N:
                arr[na][nb] += floor(arr[a][b] * t[i+2][j+2])
            else:
                ans += floor(arr[a][b] * t[i+2][j+2])
            alpha -= floor(arr[a][b] * t[i+2][j+2])

    if 0 <= a+dx[d] < N and 0 <= b+dy[d] <N:
        arr[a+dx[d]][b+dy[d]] += alpha
    else:
        ans += alpha


while not (x == 0 and y == 0):
    nx = x + dx[d]
    ny = y + dy[d]

    move_sand(nx, ny, d, arr)

    move_cnt += 1
    if move_cnt == move_scale:
        d = (d+1) % 4
    elif move_cnt == move_scale * 2:
        move_cnt = 0
        move_scale += 1
        d = (d+1) % 4
    x = nx
    y = ny

print(ans)
