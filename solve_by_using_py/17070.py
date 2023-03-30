import sys
input = sys.stdin.readline

N = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]
cnt = 0

def dfs(x, y, d):
    global cnt
    if x == N-1 and y == N-1:
        cnt += 1
        return

    if x + 1 < N and y + 1 < N:
        if graph[x + 1][y + 1] == 0 and graph[x][y + 1] == 0 and graph[x + 1][y] == 0:
            dfs(x + 1, y + 1, 2)

    if d == 0 or d == 2:
        if y + 1 < N:
            if graph[x][y + 1] == 0:
                dfs(x, y + 1, 0)

    if d == 1 or d == 2:
        if x + 1 < N:
            if graph[x + 1][y] == 0:
                dfs(x + 1, y, 1)

if graph[N-1][N-1] == 1:
    print(cnt)
else:
    dfs(0, 1, 0)
    print(cnt)
