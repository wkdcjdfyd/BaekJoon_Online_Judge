import sys
input = sys.stdin.readline

def find_set(x):
    while x != parents[x]:
        x = parents[x]
    return x

N, M = map(int, input().split())
gender = input().split()
gender.insert(0, None)
edges = []
for _ in range(M):
    u, v, d = map(int, input().split())
    edges.append((u, v, d))

edges.sort(key=lambda x: x[2])

parents = [x for x in range(N+1)]
dist, cnt = 0, 0

for u, v, d in edges:
    if gender[u] != gender[v] and find_set(u) != find_set(v):
        parents[find_set(v)] = find_set(u)
        dist += d
        cnt += 1
    if cnt == N-1:
        break
if cnt != N-1:
    dist = -1
print(dist)
