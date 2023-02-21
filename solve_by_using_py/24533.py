import sys
input = sys.stdin.readline

N = int(input())
a, b = map(int, input().split())
ans = 0

for _ in range(N-1):
    x, y = map(int, input().split())
    ans += a*y + b*x
    a += x
    b += y
print(ans)
