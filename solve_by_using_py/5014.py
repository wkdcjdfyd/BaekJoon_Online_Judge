from collections import deque

F, S, G, U, D = map(int, input().split())
visited = [-1] * (F+1)
q = deque()
q.append((S, 0))
visited[S] = 0

while q:
    now, cnt = q.popleft()
    if now == G:
        print(cnt)
        break

    nxt_u = now + U
    nxt_d = now - D

    if nxt_u <= F and visited[nxt_u] == -1:
        visited[nxt_u] = cnt+1
        q.append((nxt_u, cnt+1))
    if nxt_d >= 1 and visited[nxt_d] == -1:
        visited[nxt_d] = cnt+1
        q.append((nxt_d, cnt+1))
else:
    print('use the stairs')
