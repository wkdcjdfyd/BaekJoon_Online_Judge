import sys

input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
dp = A[:]

for i in range(N):
    for j in range(0, i):
        if A[j] < A[i] and dp[i] < dp[j] + A[i]:
            dp[i] = dp[j] + A[i]

print(max(dp))
