from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

N, M, K = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

def bfs(a, b, cnt):
    q = deque()
    q.append((a, b))
    arr[a][b] = cnt
    mush_num = 1

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < N and 0 <= ny < N:
                if arr[nx][ny] == 0:
                    q.append((nx, ny))
                    arr[nx][ny] = cnt
                    mush_num += 1
    return mush_num

check = 0
ans = 0
for i in range(N):
    for j in range(N):
        if arr[i][j] == 0:
            check -= 1
            num = bfs(i, j , check)

            if num % K == 0:
                ans += num // K
            else:
                ans += (num // K) + 1

if M == 0 or ans == 0 or M < ans:
    print("IMPOSSIBLE")
else:
    print("POSSIBLE")
    print(M - ans)
