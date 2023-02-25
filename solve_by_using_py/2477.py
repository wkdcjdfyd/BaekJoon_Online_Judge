K = int(input())
EAST = 1
WEST = 2
SOUTH = 3
NORTH = 4
edges = []
graph = [[] for _ in range(5)]

for _ in range(6):
    d, length = map(int, input().split())
    graph[d].append(length)
    edges.append([d, length])

if len(graph[EAST]) == 1 and len(graph[SOUTH]) == 1:
    ans = graph[EAST][0] * graph[SOUTH][0]
    for i in range(6):
        if edges[i][0] == EAST:
            break
elif len(graph[EAST]) == 1 and len(graph[NORTH]) == 1:
    ans = graph[EAST][0] * graph[NORTH][0]
    for i in range(6):
        if edges[i][0] == NORTH:
            break
elif len(graph[WEST]) == 1 and len(graph[NORTH]) == 1:
    ans = graph[WEST][0] * graph[NORTH][0]
    for i in range(6):
        if edges[i][0] == WEST:
            break
elif len(graph[WEST]) == 1 and len(graph[SOUTH]) == 1:
    ans = graph[WEST][0] * graph[SOUTH][0]
    for i in range(6):
        if edges[i][0] == SOUTH:
            break

idx1 = (i + 2) % 6
idx2 = (i + 3) % 6
ans -= edges[idx1][1] * edges[idx2][1]

print(ans*K)
