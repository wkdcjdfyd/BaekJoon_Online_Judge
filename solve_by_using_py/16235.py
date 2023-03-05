import sys
input = sys.stdin.readline

dx = [-1, -1, -1, 0, 0, 1, 1, 1]
dy = [-1, 0, 1, -1, 1, -1, 0, 1]

N, M, K = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]
graph = [[5] * (N+1) for _ in range(N+1)]
tree_graph = [[[] for _ in range(N+1)] for _ in range(N+1)]

for _ in range(M):
    x, y, age = map(int, input().split())
    tree_graph[x][y].append(age)

for i in range(K):
    grow = []
    pop = []
    for x in range(1, N+1):
        for y in range(1, N+1):
            energy = graph[x][y]
            nxt = 0
            for t in range(len(tree_graph[x][y])-1, -1, -1):
                if energy >= tree_graph[x][y][t]:
                    energy -= tree_graph[x][y][t]
                    tree_graph[x][y][t] += 1

                    if tree_graph[x][y][t] % 5 == 0:
                        grow.append((x, y))
                else:
                    nxt += tree_graph[x][y][t] // 2
                    pop.append((x, y, t))
            graph[x][y] = energy + nxt

    for x, y, t in pop:
        tree_graph[x][y].pop(t)

    for x, y in grow:
        for idx in range(8):
            nx = x + dx[idx]
            ny = y + dy[idx]
            if nx <= 0 or ny <= 0 or nx > N or ny > N:
                continue
            tree_graph[nx][ny].append(1)

    for x in range(1, N+1):
        for y in range(1, N+1):
            graph[x][y] += A[x-1][y-1]

ans = 0
for x in range(1, N+1):
        for y in range(1, N+1):
            ans += len(tree_graph[x][y])
print(ans)
