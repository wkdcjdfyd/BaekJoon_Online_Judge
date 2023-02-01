import sys
from itertools import combinations

def distance(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

input = sys.stdin.readline

N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
house = []
chicken = []
ans = int(1e9)

for i in range(N):
    for j in range(N):
        if graph[i][j] == 1:
            house.append((i, j))
        elif graph[i][j] == 2:
            chicken.append((i, j))

for chicks in combinations(chicken, M):
    city_val = 0
    for home in house:
        ch_val = 50 * 50
        for ch in chicks:
            ch_val = min(ch_val, distance(home, ch))
        city_val += ch_val
    ans = min(ans, city_val)

print(ans)
