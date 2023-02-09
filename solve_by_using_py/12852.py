N = int(input())
dp = [[0, 0] for i in range(N+1)]

for now in range(1, N+1):
    for nxt in [now+1, now*2, now*3]:
        if nxt > N:
            continue
        if not dp[nxt][0] or dp[nxt][0] > dp[now][0] + 1:
            dp[nxt][0] = dp[now][0] + 1
            dp[nxt][1] = now

print(dp[N][0])
print(N, end=' ')
while N:
    N = dp[N][1]
    if not N:
        break
    print(N, end=' ')
