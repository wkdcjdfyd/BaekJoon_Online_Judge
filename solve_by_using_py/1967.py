import sys
sys.setrecursionlimit(10**5)

input = sys.stdin.readline

n = int(input())
graph = [[] for _ in range(n+1)]

for _ in range(n-1):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

def dfs(x):
    visited[x] = 1

    for nxt, cost in graph[x]:
        if visited[nxt] != 1 and dist[nxt] < dist[x] + cost:
            dist[nxt] = dist[x] + cost
            dfs(nxt)

x = 1
for i in range(2):
    dist = [0] * (n+1)
    visited = [0] * (n+1)
    dfs(x)
    val = 0
    idx = 0
    for j in range(1, n+1):
        if val < dist[j]:
            val = dist[j]
            idx = j
    x = idx

print(val)
