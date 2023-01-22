import sys
input = sys.stdin.readline

N, K = map(int, input().split())
stuff = [(0, 0)]
knapsack = [[0] * (K+1) for _ in range(N+1)]

for _ in range(N):
    W, V = map(int, input().split())
    stuff.append((W, V))

for i in range(1, N+1):
    for j in range(1, K+1):
        w, v = stuff[i][0], stuff[i][1]

        if j < w:
            knapsack[i][j] = knapsack[i-1][j]
        else:
            knapsack[i][j] = max(v + knapsack[i-1][j-w], knapsack[i-1][j])

print(knapsack[N][K])
