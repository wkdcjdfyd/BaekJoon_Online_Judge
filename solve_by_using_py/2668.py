from collections import defaultdict

N = int(input())
graph = defaultdict(list)
checked = [0] * (N+1)
for i in range(1, N+1):
    key = int(input())
    graph[key].append(i)
result = []

def dfs(x, visited):
    checked[x] = 1
    visited.add(x)
    for item in graph[x]:
        if item not in visited:
            dfs(item, visited.copy())
        else:
            result.extend(list(visited))
            return

for i in range(1, N+1):
    if not checked[i]:
        dfs(i, set([]))
result.sort()
print(len(result))
for x in result:
    print(x)
