from collections import deque

N, W = map(int, input().split())
graph = [[] for _ in range(N+1)]
visited = [0] * (N+1)

for _ in range(N-1):
    U, V = map(int, input().split())
    graph[U].append(V)
    graph[V].append(U)

def bfs(start):
    cnt = 0
    q = deque()
    q.append(start)
    visited[1] = 1

    while q:
        now = q.popleft()
        if now != 1 and len(graph[now]) == 1:
            cnt += 1
            continue

        for n in graph[now]:
            if visited[n] == 0:
                visited[n] = 1
                q.append(n)
    return cnt

ans = bfs(1)
print("{:.4f}".format(W/ans))
