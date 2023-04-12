from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

T = int(input())

def bfs(a, b, g, v, cnt):
    q = deque()
    q.append((a, b))
    v[a][b] = cnt

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < H and 0 <= ny < W:
                if g[nx][ny] == '#' and v[nx][ny] == 0:
                    v[nx][ny] = cnt
                    q.append((nx, ny))


for tc in range(T):
    H, W = map(int, input().split())
    graph = [list(input()) for _ in range(H)]
    visited = [[0] * W for _ in range(H)]
    cnt = 0
    ans = 0

    for i in range(H):
        for j in range(W):
            if graph[i][j] == '#' and visited[i][j] == 0:
                cnt += 1
                bfs(i, j, graph, visited, cnt)

    print(cnt)
