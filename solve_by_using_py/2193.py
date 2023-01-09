N = int(input())
dp = [0] * (N+1)
dp[1] = 1

num_last_zero = [0] * (N+1)
num_last_zero[1] = 0

for i in range(2, N+1):
    dp[i] = num_last_zero[i-1] * 2 + dp[i-1] - num_last_zero[i-1]
    num_last_zero[i] = dp[i-1]
print(dp[N])
