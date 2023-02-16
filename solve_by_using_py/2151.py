import heapq

INF = int(1e6)

N = int(input())
home = [list(input()) for _ in range(N)]
door = []
mir = []

mir_cnt = 2

for i in range(N):
    for j in range(N):
        if home[i][j] == '#':
            door.append((i, j))
        elif home[i][j] == '!':
            home[i][j] = mir_cnt
            mir_cnt += 1
            mir.append((i, j))

home[door[0][0]][door[0][1]] = 1
home[door[1][0]][door[1][1]] = mir_cnt

node = [[], door[0]] + mir + [door[1]]
graph = [[] for _ in range(mir_cnt+1)]
distance = [INF] * len(node)

for node, (x, y) in enumerate(node[1:]):
    for j in range(y-1, -1, -1):
        if home[x][j] == '*':
            break
        elif type(home[x][j]) == int:
            graph[node + 1].append((home[x][j], 1))
    for j in range(y+1, N):
        if home[x][j] == '*':
            break
        elif type(home[x][j]) == int:
            graph[node + 1].append((home[x][j], 1))
    for i in range(x-1, -1, -1):
        if home[i][y] == '*':
            break
        elif type(home[i][y]) == int:
            graph[node + 1].append((home[i][y], 1))
    for i in range(x+1, N):
        if home[i][y] == '*':
            break
        elif type(home[i][y]) == int:
            graph[node + 1].append((home[i][y], 1))

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0

    while q:
        dist, now = heapq.heappop(q)
        if dist > distance[now]:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))
    print(distance[-1]-1)

dijkstra(1)