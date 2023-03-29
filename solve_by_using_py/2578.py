graph = [list(map(int, input().split())) for _ in range(5)]
visited = [[0] * 5 for _ in range(5)]
order = []

for _ in range(5):
    order.extend(list(map(int, input().split())))

def find(x):
    for i in range(5):
        for j in range(5):
            if graph[i][j] == x:
                return i, j
    return -1, -1

def bingo_check():
    cnt = 0

    for i in range(5):
        for j in range(5):
            if visited[i][j] != 1:
                break
        else:
            cnt += 1

        for j in range(5):
            if visited[j][i] != 1:
                break
        else:
            cnt += 1

    for i in range(5):
        if visited[i][i] != 1:
            break
    else:
        cnt += 1

    for i in range(5):
        if visited[4-i][i] != 1:
            break
    else:
        cnt += 1

    return cnt

for i in range(len(order)):
    x, y = find(order[i])
    visited[x][y] = 1
    if i >= 11:
        count = bingo_check()
        if count >= 3:
            print(i+1)
            break
