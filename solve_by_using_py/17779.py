N = int(input())
graph = [[0] * (N+1)]
for _ in range(N):
    graph.append([0] + list(map(int, input().split())))

def check_popul(x, y, d1, d2):
    area = [[0] * (N+1) for _ in range(N+1)]
    popul = [0] * 5
    i, j = x-1, y+1
    while i != x+d1 and j != y-d1:
        i += 1
        j -= 1
        area[i][j] = 5

    i, j = x-1, y-1
    while i != x+d2 and j != y+d2:
        i += 1
        j += 1
        area[i][j] = 5

    i, j = x+d1-1, y-d1-1
    while i != x+d1+d2 and j != y-d1+d2:
        i += 1
        j += 1
        area[i][j] = 5

    i, j = x+d2-1, y+d2+1
    while i != x+d2+d1 and j != y+d2-d1:
        i += 1
        j -= 1
        area[i][j] = 5

    for i in range(1, x+d1):
        for j in range(1, y+1):
            if area[i][j] == 5:
                break
            area[i][j] = 1
            popul[0] += graph[i][j]
    for i in range(1, x+d2+1):
        for j in range(N, y, -1):
            if area[i][j] == 5:
                break
            area[i][j] = 2
            popul[1] += graph[i][j]
    for i in range(x+d1, N+1):
        for j in range(1, y-d1+d2):
            if area[i][j] == 5:
                break
            area[i][j] = 3
            popul[2] += graph[i][j]
    for i in range(x+d2+1, N+1):
        for j in range(N, y-d1+d2-1, -1):
            if area[i][j] == 5:
                break
            area[i][j] = 4
            popul[3] += graph[i][j]

    total = 0
    for a in graph:
        total += sum(a)
    popul[4] = total - sum(popul)

    return max(popul) - min(popul)

ans = int(1e9)
for x in range(1, N+1):
    for y in range(1, N+1):
        for d1 in range(1, y):
            for d2 in range(1, N-y):
                if d1 + d2 <= N-x:
                    ans = min(ans, check_popul(x, y, d1, d2))

print(ans)
