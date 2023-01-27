from collections import deque

N = int(input())
arr = [x for x in range(1, N+1)]
q = deque(arr)

while len(q) != 1:
    q.popleft()
    val = q.popleft()
    q.append(val)

print(q.pop())
