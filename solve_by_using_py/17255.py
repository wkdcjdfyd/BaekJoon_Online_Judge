from collections import deque

N = input()
q = deque()
q.append(N)

while q:
    now = q.popleft()
    if len(now) == 1:
        print(len(q) + 1)
        break

    front = now[:-1]
    rear = now[1:]
    if front == rear:
        q.append(front)
    else:
        q.extend([front, rear])
