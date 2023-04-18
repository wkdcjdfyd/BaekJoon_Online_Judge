import sys
from itertools import combinations
input = sys.stdin.readline

N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
x_sum = [sum(x) for x in graph]
y_sum = [0] * M

for j in range(M):
    temp = 0
    for i in range(N):
        temp += graph[i][j]
    y_sum[j] = temp

x = [a for a in range(N)]
y = [b for b in range(M)]

ans = -10000001
for x1, x2 in combinations(x, 2):
    for y1, y2 in combinations(y, 2):
        beauty = (x2 - x1 - 1) * (y2 - y1 - 1)
        beauty += x_sum[x1]
        beauty += x_sum[x2]
        beauty += y_sum[y1]
        beauty += y_sum[y2]

        beauty -= graph[x1][y1]
        beauty -= graph[x1][y2]
        beauty -= graph[x2][y1]
        beauty -= graph[x2][y2]

        ans = max(ans, beauty)

print(ans)
