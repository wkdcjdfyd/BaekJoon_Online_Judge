dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

graph = [list(map(str, input().split())) for _ in range(5)]
result = []

def dfs(x, y, num):
    if len(num) == 6:
        if num not in result:
            result.append(num)
        return
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or ny < 0 or nx >= 5 or ny >= 5:
            continue
        dfs(nx, ny, num + graph[nx][ny])

for i in range(5):
    for j in range(5):
        dfs(i, j, graph[i][j])

print(len(result))
