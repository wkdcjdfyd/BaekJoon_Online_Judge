import sys
import heapq
input = sys.stdin.readline
INF = sys.maxsize

N, M = map(int, input().split())
visible = list(map(int, input().split()))
visible[N-1] = 0
distance = [INF] * N
graph = [[] for _ in range(N)]

for _ in range(M):
    a, b, t = map(int, input().split())
    graph[a].append((b, t))
    graph[b].append((a, t))

def dijkstra(x):
    q = []
    heapq.heappush(q, (0, x))
    distance[x] = 0

    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            if visible[i[0]]:
                continue
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

dijkstra(0)
print(distance[N-1]) if distance[N-1] != INF else print(-1)
