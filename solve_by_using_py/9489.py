import sys
input = sys.stdin.readline

while True:
    n, k = map(int, input().split())
    if n == 0 and k == 0:
        break

    nodes = [-1] + list(map(int, input().split()))
    parent = [0] * (n+1)
    parent[0] = -1
    idx = -1
    k_idx = 0

    for i in range(1, n+1):
        if nodes[i] == k:
            k_idx = i
        if nodes[i] != nodes[i-1] + 1:
            idx += 1
        parent[i] = idx

    ans = 0
    for i in range(1, n+1):
        if parent[parent[i]] == parent[parent[k_idx]] and parent[i] != parent[k_idx]:
            ans += 1
    print(ans)
