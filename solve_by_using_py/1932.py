n = int(input())

graph = [list(map(int, input().split())) for _ in range(n)]
dp = [[-1] * n for _ in range(n)]
dp[0][0] = graph[0][0]

for i in range(1, len(graph)):
    for j in range(len(graph[i])):
        if j == 0:
            dp[i][j] = dp[i-1][j] + graph[i][j]
        elif j == len(graph[i])-1:
            dp[i][j] = dp[i-1][j-1] + graph[i][j]
        else:
            if dp[i-1][j] > dp[i-1][j-1]:
                dp[i][j] = dp[i-1][j] + graph[i][j]
            else:
                dp[i][j] = dp[i-1][j-1] + graph[i][j]

print(max(dp[-1]))
