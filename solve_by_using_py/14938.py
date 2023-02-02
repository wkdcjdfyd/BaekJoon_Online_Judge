import sys
import heapq

INF = int(1e9)
input = sys.stdin.readline

n, m, r = map(int, input().split())
items = list(map(int, input().split()))

graph = [[] for _ in range(n+1)]

for _ in range(r):
    a, b, l = map(int, input().split())
    graph[a].append((b, l))
    graph[b].append((a, l))

def dijkstra(start):
    distance = [INF] * (n+1)
    distance[start] = 0
    q = []
    heapq.heappush(q, (0, start))

    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

    item_num = 0
    for i in range(1, n+1):
        if distance[i] <= m:
            item_num += items[i-1]
    return item_num

ans = -INF
for i in range(1, n+1):
    ans = max(ans, dijkstra(i))

print(ans)
