import sys

input = sys.stdin.readline

N = int(input())
children = list(map(int, input().split()))
dp = [0] * (N+1)

for child in children:
    dp[child] = dp[child-1] + 1

print(N - max(dp))
