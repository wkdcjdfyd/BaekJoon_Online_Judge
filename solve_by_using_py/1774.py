import sys
input = sys.stdin.readline

def distance(x, y):
    return ((x[0] - y[0])**2 + (x[1] - y[1])**2)**(1/2)

def find_set(x):
    while x != parents[x]:
        x = parents[x]
    return x

N, M = map(int, input().split())
parents = [x for x in range(N+1)]
loc = [list(map(int, input().split())) for _ in range(N)]
loc.insert(0, [-1, -1])

for _ in range(M):
    x, y = map(int, input().split())
    parents[find_set(x)] = find_set(y)

edges = []
for i in range(1, N+1):
    for j in range(i, N+1):
        if find_set(i) != find_set(j):
            edges.append((i, j, distance(loc[i], loc[j])))
edges.sort(key=lambda x: x[2])

dist = 0
cnt = M

for u, v, d in edges:
    if find_set(u) != find_set(v):
        parents[find_set(v)] = find_set(u)
        dist += d
        cnt += 1
    if cnt == N-1:
        break

print(format(round(dist, 2),".2f"))
