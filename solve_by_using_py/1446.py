import heapq

N, D = map(int, input().split())
graph = [[] for _ in range(10001)]
distance = [20000] * 10001

for _ in range(N):
    x, y, cost = map(int, input().split())
    if y - x > cost:
        graph[x].append((y, cost))

for i in range(D):
    graph[i].append((i+1, 1))

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0

    while q:
        dist, now = heapq.heappop(q)
        if dist > distance[now]:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

dijkstra(0)
print(distance[D])
