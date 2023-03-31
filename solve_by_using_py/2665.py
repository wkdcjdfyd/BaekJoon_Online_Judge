import heapq

INF = int(1e6)
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

n = int(input())
graph = [list(map(int, ' '.join(input()).split())) for _ in range(n)]
distance = [[INF] * n for _ in range(n)]

def dijkstra(a, b):
    q = []
    heapq.heappush(q, (0, a, b))
    distance[a][b] = 0

    while q:
        dist, x, y = heapq.heappop(q)
        if dist > distance[x][y]:
            continue

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or ny < 0 or nx >= n or ny >= n:
                continue
            if graph[nx][ny] == 0:
                cost = dist + 1
            else:
                cost = dist
            if cost < distance[nx][ny]:
                distance[nx][ny] = cost
                heapq.heappush(q, (cost, nx, ny))

dijkstra(0, 0)
print(distance[n-1][n-1])
