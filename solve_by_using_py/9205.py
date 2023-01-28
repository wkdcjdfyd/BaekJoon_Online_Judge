import sys
from collections import deque

input = sys.stdin.readline

def distance(s, e):
    return abs(s[0] - e[0]) + abs(s[1] - e[1])

def bfs(start_idx):
    q = deque()
    q.append(start_idx)
    visited[start_idx] = 1
    result = False

    while q:
        now = q.popleft()
        if now == len(loc) - 1:
            result = True
            break
        for idx in range(len(loc)):
            if visited[idx] == 0 and distance(loc[now], loc[idx]) <= 1000:
                q.append(idx)
                visited[idx] = 1

    return result

T = int(input())

for _ in range(T):
    n = int(input())
    loc = [list(map(int, input().split())) for _ in range(n+2)]
    visited = [0] * (n+2)
    if bfs(0):
        print('happy')
    else:
        print('sad')