N = int(input())
M = int(input())
graph = [[] for _ in range(N+1)]
visited = [False] * (N + 1)
result = 0

for i in range(M):
    start, end = map(int, input().split())
    graph[start].append(end)
    graph[end].append(start)

def dfs(num):
    global result
    stack = [num]

    now = stack.pop()
    visited[now] = True

    for i in graph[now]:
        if visited[i]:
            continue
        result += 1
        dfs(i)

dfs(1)
print(result)
