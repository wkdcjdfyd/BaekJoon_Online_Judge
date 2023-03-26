H, W = map(int, input().split())

graph = [list(input().rstrip()) for _ in range(H)]

for i in range(H):
    cnt = 0
    for j in range(W):
        if graph[i][j] == '.':
            if cnt == 0:
                graph[i][j] = -1
            else:
                graph[i][j] = cnt
                cnt += 1
        elif graph[i][j] == 'c':
            graph[i][j] = 0
            cnt = 1

for i in range(H):
    print(*graph[i])
