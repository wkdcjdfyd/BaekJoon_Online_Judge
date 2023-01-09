T = int(input())
dp = [[i for i in range(1, 15)]]

for i in range(1, 15):
    temp = []
    res = 0
    for j in dp[i-1]:
        res += j
        temp.append(res)
    dp.append(temp)

for _ in range(T):
    k = int(input())
    n = int(input())
    print(dp[k][n-1])