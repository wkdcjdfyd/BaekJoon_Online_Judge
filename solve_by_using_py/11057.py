N = int(input())
dp = [[1] * 10 for _ in range(N+1)]

for length in range(2, N+1):
    for i in range(10):
        dp[length][9] = dp[length-1][9]
        for j in range(8, -1, -1):
            dp[length][j] = (dp[length][j+1] + dp[length-1][j]) % 10007

print(sum(dp[N])%10007)
