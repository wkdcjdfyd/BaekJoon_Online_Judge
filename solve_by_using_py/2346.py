from collections import deque

N = int(input())
ball = list(map(int, input().split()))
ball_num = []

for idx, v in enumerate(ball):
    ball_num.append((idx, v))

q = deque(ball_num)

while q:
    idx, val = q.popleft()
    print(idx+1, end=' ')

    if val > 0:
        q.rotate(-(val - 1))
    elif val < 0:
        q.rotate(-val)
