import sys
import heapq

INF = int(1e9) + 1
input = sys.stdin.readline

N = int(input())
T, M = map(int, input().split())
L = int(input())
graph = [[] for _ in range(N+1)]
distance1 = [[INF, INF]] * (N+1)
distance2 = [[INF, INF]] * (N+1)

for _ in range(L):
    a, b, t, m = map(int, input().split())
    graph[a].append((b, t, m))
    graph[b].append((a, t, m))

def dijkstra1(x):
    q = []
    heapq.heappush(q, (0, 0, x))
    distance1[x] = [0, 0]

    while q:
        money, time, now = heapq.heappop(q)
        if money > distance1[now][0] or time > distance1[now][1]:
            continue

        for next, t, m in graph[now]:
            nt = time + t
            nm = money + m
            if nt > T or nm > M:
                continue
            if nm < distance1[next][0]:
                distance1[next] = [nm, nt]
                heapq.heappush(q, (nm, nt, next))

def dijkstra2(x):
    q = []
    heapq.heappush(q, (0, 0, x))
    distance2[x] = [0, 0]

    while q:
        money, time, now = heapq.heappop(q)
        if money > distance2[now][0] or time > distance2[now][1]:
            continue

        for next, t, m in graph[now]:
            nt = time + t
            nm = money + m
            if nt > T or nm > M:
                continue
            if nt < distance2[next][1]:
                distance2[next] = [nm, nt]
                heapq.heappush(q, (nm, nt, next))

dijkstra1(1)
dijkstra2(1)

if distance1[N][0] == INF and distance2[N][0] == INF:
    print(-1)
elif distance1[N][0] == INF:
    print(distance2[N][0])
elif distance2[N][0] == INF:
    print(distance1[N][0])
else:
    print(min(distance1[N][0], distance2[N][0]))
