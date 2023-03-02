import sys
from copy import deepcopy

input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
dp = deepcopy(A)

for i in range(N):
    for j in range(0, i):
        if A[j] < A[i] and dp[i] < dp[j] + A[i]:
            dp[i] = dp[j] + A[i]

print(max(dp))
