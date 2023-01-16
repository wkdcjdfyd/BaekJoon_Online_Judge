import sys
input = sys.stdin.readline

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

N, M = map(int, input().split())
R, C, D = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
ans = 0

def search(r, c, d):
    global ans

    if graph[r][c] == 0:
        ans += 1
        graph[r][c] = -1

    left = d
    for i in range(4):
        left = left - 1 if left != 0 else 3
        nr = r + dr[left]
        nc = c + dc[left]
        if nr < 0 or nc < 0 or nr >= N or nc >= M:
            continue
        if graph[nr][nc] == 0:
            search(nr, nc, left)
            break
    else:
        back = (d + 2) % 4
        nr = r + dr[back]
        nc = c + dc[back]
        if graph[nr][nc] == 1:
            print(ans)
            exit()
        else:
            search(nr, nc, d)

search(R, C, D)
