import sys
import heapq

INF = int(1e10)
input = sys.stdin.readline

N, M = map(int, input().split())
graph = [[] for _ in range(N+1)]
distance = [INF] * (N+1)

for _ in range(M):
    a, b, c = map(int, input().split())
    graph[a].append((b ,c))
    graph[b].append((a, c))

def dijkstra(x):
    q = []
    heapq.heappush(q, (0, x))
    distance[x] = 0

    while q:
        dist, now = heapq.heappop(q)

        if dist > distance[now]:
            continue

        for i in graph[now]:
            cost = dist + i[1]
            if distance[i[0]] > cost:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

dijkstra(1)
print(distance[N])