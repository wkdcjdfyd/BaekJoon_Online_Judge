dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

N = int(input())

def dfs(x, y, pin, cnt):
    global pin_result, move_result

    if pin <= pin_result:
        pin_result = pin
        move_result = cnt

    for d in range(4):
        nx = x + dx[d]
        ny = y + dy[d]

        if 0 <= nx < 5 and 0 <= ny < 9:
            if graph[nx][ny] == 'o':
                nnx = nx + dx[d]
                nny = ny + dy[d]
                if 0 <= nnx < 5 and 0 <= nny < 9:
                    if graph[nnx][nny] == '.':
                        graph[x][y] = '.'
                        graph[nx][ny] = '.'
                        graph[nnx][nny] = 'o'

                        for i in range(5):
                            for j in range(9):
                                if graph[i][j] == 'o':
                                    dfs(i, j, pin-1, cnt+1)
                        graph[x][y] = 'o'
                        graph[nx][ny] = 'o'
                        graph[nnx][nny] = '.'


for tc in range(N):
    graph = [list(input().rstrip()) for _ in range(5)]
    pin_result, move_result = 0, 0
    pin_cnt = 0
    for i in range(5):
        for j in range(9):
            if graph[i][j] == 'o':
                pin_cnt += 1
    pin_result = pin_cnt
    for i in range(5):
        for j in range(9):
            if graph[i][j] == 'o':
                dfs(i, j, pin_cnt, 0)

    print(pin_result, move_result)

    if tc != N-1:
        input()

