import sys
import heapq

INF = sys.maxsize
input = sys.stdin.readline

N, M = map(int, input().split())
s, e = map(int, input().split())
graph = [[] for _ in range(N+1)]
weight = [0] * (N+1)

for _ in range(M):
    h1, h2, k = map(int, input().split())
    graph[h1].append((h2, k))
    graph[h2].append((h1, k))

def dijkstra(x):
    q = []
    heapq.heappush(q, (-INF, x))
    weight[x] = INF

    while q:
        w, now = heapq.heappop(q)
        w = -w
        if weight[now] > w:
            continue
        for h, limit in graph[now]:
            min_val = min(w, limit)
            if weight[h] < min_val:
                weight[h] = min_val
                heapq.heappush(q, (-min_val, h))

dijkstra(s)
print(weight[e])
