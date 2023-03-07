import sys
from collections import deque

input = sys.stdin.readline

dx = [1, 0, 0, -1]
dy = [0, -1, 1, 0]

R, C = map(int, input().split())
graph = [list(input().rstrip()) for _ in range(R)]
N = int(input())
H = list(map(int, input().split()))
flag = 1    # 1이면 왼쪽, -1이면 오른쪽

def find_mineral(h, flag):
    # 왼쪽부터
    if flag == 1:
        for i in range(C):
            if graph[R-h][i] != '.':
                return R-h, i
    # 오른쪽부터
    else:
        for i in range(C-1, -1, -1):
            if graph[R-h][i] != '.':
                return R-h, i
    # 못찾았을 경우
    return -1, -1

def bfs(a, b, num):
    q = deque()
    q.append((a, b))
    graph[a][b] = num
    visited = [['.'] * C for _ in range(R)]
    visited[a][b] = 1
    check_floating = 1
    cluster = [[a, b]]

    while q:
        x, y = q.popleft()
        if x == R-1:
            check_floating = 0

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= R or ny >= C:
                continue
            if visited[nx][ny] != 1 and graph[nx][ny] != '.':
                graph[nx][ny] = num
                visited[nx][ny] = 1
                q.append((nx, ny))
                cluster.append([nx, ny])

    return check_floating, cluster

def go_down(num, cluster):
    crack = 1000

    for x, y in cluster:
        for i in range(x+1, R):
            if graph[i][y] != '.' and graph[i][y] != num:
                crack = min(crack, i-x-1)
        else:
            crack = min(crack, R-x-1)

    cluster.sort(reverse=True)
    for x, y in cluster:
        graph[x+crack][y] = graph[x][y]
        graph[x][y] = '.'


for h in H:
    x, y = find_mineral(h, flag)
    flag *= -1

    for i in range(R):
        for j in range(C):
            if graph[i][j] != '.':
                graph[i][j] = 'x'

    # 높이 h에서 미네랄을 못찾았을 경우
    if x == -1 and y == -1:
        continue
    else:
        graph[x][y] = '.'

    cnt = 0
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or ny < 0 or nx >= R or ny >= C:
            continue
        if graph[nx][ny] != '.':
            cnt += 1
            floating , cluster = bfs(nx, ny, cnt)
            if floating:
                go_down(cnt, cluster)


for i in range(R):
    for j in range(C):
        if graph[i][j] != '.':
            print('x', end='')
        else:
            print('.', end='')
    print()