import sys
from copy import deepcopy
input = sys.stdin.readline

N = int(input())
dduck = [list(map(int, input().split())) for _ in range(N)]
visited = [[0]*10 for _ in range(N)]

def dfs(x, y, ans):
    temp = deepcopy(ans)
    temp.append(dduck[x][y])
    visited[x][y] = 1
    if len(temp) == N:
        for x in temp:
            print(x)
        exit()
    if x+1 == N:
        return
    for i in range(1, dduck[x+1][0]+1):
        if dduck[x][y] == dduck[x+1][i]:
            continue
        if visited[x+1][i] != 1:
            dfs(x+1, i, temp)

for j in range(1, dduck[0][0]+1):
    dfs(0, j, [])
else:
    print(-1)