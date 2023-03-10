import sys
input = sys.stdin.readline

N, L = map(int, input().split())
delay = 0

for _ in range(N):
    D, R, G = map(int, input().split())
    now = D + delay

    if now % (R+G) < R:
        delay += R - (now % (R+G))

print(L+delay)
