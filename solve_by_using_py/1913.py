dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

N = int(input())
M = int(input())
graph = [[0] * N for _ in range(N)]
x = N // 2
y = N // 2
graph[x][y] = 1
scale = 1
d = 0
cnt = 1
s_cnt = 0
ans_x = x+1
ans_y = y+1

while cnt != N**2:
    nx = x + dx[d]
    ny = y + dy[d]
    cnt += 1
    graph[nx][ny] = cnt
    if cnt == M:
        ans_x = nx + 1
        ans_y = ny + 1

    s_cnt += 1
    if s_cnt == scale:
        d = (d+1) % 4
    elif s_cnt == scale * 2:
        d = (d+1) % 4
        scale += 1
        s_cnt = 0
    x = nx
    y = ny

for g in graph:
    print(*g)
print(ans_x, ans_y)
