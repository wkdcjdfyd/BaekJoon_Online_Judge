import sys
sys.setrecursionlimit(10**7)

N, S, D = map(int, input().split())
graph = [[] for _ in range(N+1)]
visited = [0] * (N+1)
ans = 0

for _ in range(N-1):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

def dfs1(x, prev):
    child_num = 0
    for nxt in graph[x]:
        if nxt != prev:
            child_num = max(child_num, dfs1(nxt, x)+1)
    visited[x] = child_num
    return child_num

def dfs2(x, prev):
    global ans
    for nxt in graph[x]:
        if nxt != prev and visited[nxt] >= D:
            ans += 1
            dfs2(nxt, x)
            ans += 1


dfs1(S, 0)
dfs2(S, 0)
print(ans)
