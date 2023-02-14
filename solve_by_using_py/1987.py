dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def dfs(x, y, word):
    global ans
    word += graph[x][y]
    if len(word) >= len(ans):
        ans = word
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or ny < 0 or nx >= R or ny >=C:
            continue
        if graph[nx][ny] in word:
            continue
        dfs(nx, ny, word)

R, C = map(int, input().split())
graph = [list(input()) for _ in range(R)]
ans = ''

dfs(0, 0, '')
print(len(ans))