from collections import deque

INF = int(1e5) + 1

N, K = map(int, input().split())
visited = [0] * INF

q = deque()
q.append(N)

while q:
    now = q.popleft()
    if now == K:
        print(visited[now])
        break
    for nx in [now - 1, now + 1, now * 2]:
        if 0 <= nx < INF and not visited[nx]:
            visited[nx] = visited[now] + 1
            q.append(nx)
