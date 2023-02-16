N = int(input())
dp = [[1] * 10 for _ in range(N+1)]

for i in range(1, 10):
    dp[1][i] = 1

for length in range(2, N+1):
    for i in range(0, 10):
        if i == 0:
            dp[length][i] = dp[length-1][i+1]
        elif i == 9:
            dp[length][i] = dp[length-1][i-1]
        else:
            dp[length][i] = (dp[length-1][i-1] + dp[length-1][i+1]) % 1000000000

print(sum(dp[N][1:])%1000000000)
