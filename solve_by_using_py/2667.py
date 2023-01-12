N = int(input())
graph = [list(map(int, input())) for _ in range(N)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def dfs(x, y):
    global num
    if x < 0 or y < 0 or x >= N or y >= N:
        return False
    if graph[x][y] == 1:
        graph[x][y] = 0
        num += 1
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            dfs(nx, ny)
        return True
    return False

result = 0
num_list = []
for x in range(N):
    for y in range(N):
        num = 0
        if dfs(x, y):
            result += 1
            num_list.append(num)

num_list.sort()
print(result)
for x in num_list:
    print(x)
