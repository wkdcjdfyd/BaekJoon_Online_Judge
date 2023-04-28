n, m = map(int, input().split())
man = sorted(list(map(int, input().split())))
woman = sorted(list(map(int, input().split())))

dp = [[0] * (m+1) for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, m+1):
        dp[i][j] = dp[i-1][j-1] + abs(man[i-1] - woman[j-1])
        if i > j:
            dp[i][j] = min(dp[i][j], dp[i-1][j])
        elif i < j:
            dp[i][j] = min(dp[i][j], dp[i][j-1])

print(dp[n][m])
