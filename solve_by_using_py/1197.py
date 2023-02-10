import sys
input = sys.stdin.readline

def find_set(x):
    while x != parents[x]:
        x = parents[x]
    return x

V, E = map(int, input().split())
parents = [x for x in range(V+1)]
edges = sorted([list(map(int, input().split())) for _ in range(E)], key=lambda x: x[2])

dist = 0

for u, v, d in edges:
    if find_set(u) != find_set(v):
        parents[find_set(v)] = find_set(u)
        dist += d

print(dist)