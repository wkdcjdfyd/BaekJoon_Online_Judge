import sys
input = sys.stdin.readline

def find_set(x):
    while x != parents[x]:
        x = parents[x]
    return x

N, M = map(int, input().split())
parents = [x for x in range(N+1)]
edges = sorted([list(map(int, input().split())) for _ in range(M)], key=lambda x: x[2])

max_val = 0
ans = 0
cnt = 1

for u, v, d in edges:
    par_u = find_set(u)
    par_v = find_set(v)
    if par_u != par_v:
        if par_u < par_v:
            parents[par_v] = par_u
        else:
            parents[par_u] = par_v
        ans += d
        max_val = d
        cnt += 1
        if cnt == N:
            break

print(ans-max_val)
