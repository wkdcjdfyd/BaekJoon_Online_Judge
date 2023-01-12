import sys
import heapq

input = sys.stdin.readline
INF = int(1e9)

N, M, X = map(int, input().split())
graph = [[] for _ in range(N+1)]

for _ in range(M):
    x, y, z = map(int, input().split())
    graph[x].append((y, z))

def dijkstra(start):
    distance = [INF] * (N + 1)
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0

    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))
    return distance

result = [0] * (N+1)
for i in range(1, N+1):
    go = dijkstra(i)
    result[i] = go[X]
back = dijkstra(X)
result = [result[i] + back[i] for i in range(N+1)]
print(max(result[1:]))
