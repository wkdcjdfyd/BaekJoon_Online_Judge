n = int(input())
arr = list(map(int, input().split()))
dp = [0] * n
dp[0] = arr[0]

# dp[i-1]이 i-1까지의 연속합의 최대값을 보장한다고 가정하자
for i in range(1, n):
    if dp[i-1] < 0:
        dp[i] = arr[i]
    else:
        dp[i] = dp[i-1] + arr[i]
print(max(dp))
