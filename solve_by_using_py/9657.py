N = int(input())

dp = [0] * 1001

dp[1] = 1
dp[2] = 0
dp[3] = 1
dp[4] = 1
dp[5] = 1

for i in range(6, N+1):
    if not dp[i-1] or not dp[i-3] or not dp[i-4]:
        dp[i] = 1

print('SK') if dp[N] == 1 else print('CY')
