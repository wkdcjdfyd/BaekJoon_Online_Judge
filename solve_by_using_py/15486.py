import sys
input = sys.stdin.readline

N = int(input())
work = [[] for _ in range(N+1)]

for i in range(1, N+1):
    T, P = map(int, input().split())
    if i+T-1 <= N:
        work[i+T-1].append((i, P))

dp = [0] * (N+1)

for now in range(1, N+1):
    if len(work[now]) == 0:
        dp[now] = dp[now-1]
    else:
        val = -1
        for idx, p in work[now]:
            if val < dp[idx-1] + p:
                val = dp[idx-1] + p
        if val < dp[now-1]:
            dp[now] = dp[now-1]
        else:
            dp[now] = val

print(dp[N])
