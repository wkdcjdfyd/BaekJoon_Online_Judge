dx = [-1, 1, 0, 0]
dy = [0, 0 ,-1, 1]

N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]

def search(x, y):
    cnt = 2

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or ny < 0 or nx >= N or ny >= M:
            cnt += graph[x][y]
            continue
        if graph[nx][ny] < graph[x][y]:
            cnt += graph[x][y] - graph[nx][ny]
    return cnt

ans = 0
for x in range(N):
    for y in range(M):
        ans += search(x, y)

print(ans)
