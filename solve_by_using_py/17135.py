import sys
from copy import deepcopy
from itertools import combinations

input = sys.stdin.readline

N, M, D = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
enemy = []
castle = [i for i in range(M)]

for i in range(N):
    for j in range(M):
        if graph[i][j] == 1:
            enemy.append([i ,j])

ans = -100
for archers in combinations(castle, 3):
    g = deepcopy(graph)
    e = deepcopy(enemy)
    kill = 0

    while e:
        shortest = [[20, 20, 100] for _ in range(3)]

        for i in range(3):
            for x, y in e:
                dist = abs(archers[i]-y) + abs(N-x)
                if dist <= D and shortest[i][2] >= dist:
                    if shortest[i][2] == dist:
                        if shortest[i][1] > y:
                            shortest[i] = [x, y, dist]
                    else:
                        shortest[i] = [x, y, dist]

        short = []

        for x, y, _ in shortest:
            if x == 20:
                continue
            if [x, y] not in short:
                short.append([x, y])

        for x, y in short:
            kill += 1
            e.remove([x, y])

        for i in range(len(e)-1, -1, -1):
            if e[i][0] == N-1:
                e.pop(i)
            else:
                e[i][0] += 1

    if ans < kill:
        ans = kill

print(ans)
