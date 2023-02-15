import sys
input = sys.stdin.readline

graph = [list(map(int, list(input().rstrip()))) for _ in range(9)]
num = [x for x in range(1, 10)]
blank = [(x, y) for x in range(9) for y in range(9) if not graph[x][y]]

def search(n):
    if n == len(blank):
        for x in graph:
            print(*x, sep='')
        exit()

    x, y = blank[n]
    box_x = (x // 3) * 3
    box_y = (y // 3) * 3
    cand = num[:]

    for i in range(box_x, box_x+3):
        for j in range(box_y, box_y+3):
            if graph[i][j] in cand:
                cand.remove(graph[i][j])

    for i in range(9):
        if graph[x][i] in cand:
            cand.remove(graph[x][i])
        if graph[i][y] in cand:
            cand.remove(graph[i][y])

    for i in cand:
        graph[x][y] = i
        search(n+1)
    graph[x][y] = 0

search(0)
