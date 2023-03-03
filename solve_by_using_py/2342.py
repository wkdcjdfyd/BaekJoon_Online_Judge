import sys
sys.setrecursionlimit(10**6)

order = list(map(int, sys.stdin.readline().rstrip().split()))
dp = [[[-1] * 5 for _ in range(5)] for _ in range(len(order))]


def cost(di, num):
    if di == 0:
        return 2
    x = abs(di - num)
    if x == 0:
        return 1
    elif x % 2 == 1:
        return 3
    elif x % 2 == 0:
        return 4

def sol(n, l, r):
    if n >= len(order) - 1:
        return 0
    if dp[n][l][r] != -1:
        return dp[n][l][r]

    dp[n][l][r] = min(sol(n+1, order[n], r) + cost(l, order[n]), sol(n+1, l, order[n]) + cost(r, order[n]))
    return dp[n][l][r]

print(sol(0, 0, 0))
