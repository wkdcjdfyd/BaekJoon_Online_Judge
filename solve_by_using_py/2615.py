from collections import deque

dx = [-1, -1, -1, 0, 1, 1, 1, 0]
dy = [-1, 0, 1, 1, 1, 0, -1, -1]

graph = [list(map(int, input().split())) for _ in range(19)]

def is_win(x, y):
    for i in range(4):
        q = deque()
        cord = [[x, y]]

        nx = x + dx[i]
        ny = y + dy[i]
        nnx = x + dx[i+4]
        nny = y + dy[i+4]

        if 0 <= nx < 19 and 0 <= ny < 19:
            if graph[nx][ny] == graph[x][y]:
                cord.append([nx, ny])
                q.append((nx, ny, i))
        if 0 <= nnx < 19 and 0 <= nny < 19:
            if graph[nnx][nny] == graph[x][y]:
                cord.append([nnx, nny])
                q.append((nnx, nny, i+4))

        while q:
            a, b, d = q.popleft()

            na = a + dx[d]
            nb = b + dy[d]
            if 0 <= na < 19 and 0 <= nb < 19:
                if graph[na][nb] == graph[x][y]:
                    cord.append([na, nb])
                    q.append((na, nb, d))

        if len(cord) == 5:
            cord.sort(key=lambda x: [x[1], x[0]])
            print(graph[x][y])
            print(cord[0][0]+1, cord[0][1]+1)
            exit()

for x in range(19):
    for y in range(19):
        if graph[x][y] != 0:
            is_win(x, y)
print(0)
