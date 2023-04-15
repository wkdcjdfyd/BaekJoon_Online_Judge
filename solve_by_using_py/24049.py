N, M = map(int, input().split())
graph = [[0] * (M+1) for _ in range(N+1)]
left = list(map(int, input().split()))
up = list(map(int, input().split()))

for i in range(1, len(left)+1):
    graph[i][0] = left[i-1]

for i in range(1, len(up)+1):
    graph[0][i] = up[i-1]

for i in range(1, N+1):
    for j in range(1, M+1):
        if graph[i-1][j] == graph[i][j-1]:
            graph[i][j] = 0
        else:
            graph[i][j] = 1
print(graph[N][M])
