import sys
sys.setrecursionlimit(10**6)

dx = [0, 1, 1, 1, 0, -1, -1, -1]
dy = [-1, -1, 0, 1, 1, 1, 0, -1]

def dfs(x, y):
    if x < 0 or y < 0 or x >= h or y >= w:
        return False
    if graph[x][y] == 1:
        graph[x][y] = 0
        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]
            dfs(nx, ny)
        return True
    return False

while True:
    w, h = map(int, input().split())
    if w == 0 and h == 0:
        break
    graph = []

    for i in range(h):
        graph.append(list(map(int, input().split())))

    result = 0
    for x in range(h):
        for y in range(w):
            if dfs(x, y):
                result += 1
    print(result)
