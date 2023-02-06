T = int(input())

for testcase in range(T):
    N = int(input())
    h = list(map(int, input().split()))
    h.sort()
    length = len(h)
    new_h = [0] * length
    j = 0
    for i in range(0, length, 2):
        new_h[j] = h[i]
        j += 1
    if length % 2 == 1:
        for i in range(length-2, -1, -2):
            new_h[j] = h[i]
            j += 1
    else:
        for i in range(length-1, -1, -2):
            new_h[j] = h[i]
            j += 1

    ans = -int(1e9)
    for i in range(N):
        val = abs(new_h[i] - new_h[i-1])
        if val > ans:
            ans = val

    print(ans)
