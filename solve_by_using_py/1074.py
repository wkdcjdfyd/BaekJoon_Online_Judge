N, r, c = map(int, input().split())
ans = 0

while N:
    if r < 2**(N - 1) and c < 2**(N - 1):
        ans += (2**(N - 1)) * (2**(N - 1)) * 0
    elif r < 2**(N - 1) <= c:
        ans += (2**(N - 1)) * (2**(N - 1)) * 1
        c -= 2**(N - 1)
    elif c < 2**(N - 1) <= r:
        ans += (2**(N - 1)) * (2**(N - 1)) * 2
        r -= 2**(N - 1)
    else:
        ans += (2**(N - 1)) * (2**(N - 1)) * 3
        c -= 2 ** (N - 1)
        r -= 2 ** (N - 1)
    N -= 1
print(ans)
