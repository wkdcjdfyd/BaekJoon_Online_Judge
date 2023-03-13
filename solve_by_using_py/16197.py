import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

N, M = map(int, input().split())
graph = [list(input().rstrip()) for _ in range(N)]
coin_loc = []

for i in range(N):
    for j in range(M):
        if graph[i][j] == 'o':
            coin_loc.append([i, j])

ans = 100000
def dfs(c1, c2, cnt):
    global ans

    if cnt+1 > 10:
        return

    for i in range(4):
        nx1 = c1[0] + dx[i]
        ny1 = c1[1] + dy[i]
        nx2 = c2[0] + dx[i]
        ny2 = c2[1] + dy[i]

        if 0 <= nx1 < N and 0 <= ny1 < M and 0 <= nx2 < N and 0 <= ny2 < M:
            if graph[nx1][ny1] == '#':
                nx1, ny1 = c1[0], c1[1]
            if graph[nx2][ny2] == '#':
                nx2, ny2 = c2[0], c2[1]

            dfs([nx1, ny1], [nx2, ny2], cnt + 1)

        elif 0 <= nx1 < N and 0 <= ny1 < M:
            ans = min(ans, cnt+1)
            continue
        elif 0 <= nx2 < N and 0 <= ny2 < M:
            ans = min(ans, cnt+1)
            continue
        else:
            continue

dfs(coin_loc[0], coin_loc[1], 0)

print(ans) if ans != 100000 else print(-1)
