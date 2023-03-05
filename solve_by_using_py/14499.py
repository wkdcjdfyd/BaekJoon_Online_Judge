import sys
from copy import deepcopy

input = sys.stdin.readline

dx = [0, 0, 0, -1, 1]
dy = [0, 1, -1, 0, 0]

N, M, x, y, K = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
order = list(map(int, input().split()))
dice = [0] * 6

def move_dice(o):
    global dice
    temp = deepcopy(dice)
    if o == 1:
        temp[0] = dice[2]
        temp[1] = dice[0]
        temp[2] = dice[5]
        temp[5] = dice[1]
    elif o == 2:
        temp[0] = dice[1]
        temp[1] = dice[5]
        temp[2] = dice[0]
        temp[5] = dice[2]
    elif o == 3:
        temp[0] = dice[4]
        temp[3] = dice[0]
        temp[4] = dice[5]
        temp[5] = dice[3]
    elif o == 4:
        temp[0] = dice[3]
        temp[3] = dice[5]
        temp[4] = dice[0]
        temp[5] = dice[4]
    dice = temp
    return

for o in order:
    nx = x + dx[o]
    ny = y + dy[o]
    if nx < 0 or ny < 0 or nx >= N or ny >= M:
        continue
    move_dice(o)
    if graph[nx][ny] == 0:
        graph[nx][ny] = dice[5]
        print(dice[0])
    else:
        dice[5] = graph[nx][ny]
        graph[nx][ny] = 0
        print(dice[0])
    x = nx
    y = ny
