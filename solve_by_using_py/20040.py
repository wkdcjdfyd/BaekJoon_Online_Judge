n, m = map(int, input().split())
parent = [x for x in range(n)]

def find_set(x):
    while x != parent[x]:
        x = parent[x]
    return x

for i in range(1, m+1):
    x, y = map(int, input().split())
    if find_set(x) != find_set(y):
        parent[find_set(y)] = parent[find_set(x)]
    else:
        print(i)
        break
else:
    print(0)