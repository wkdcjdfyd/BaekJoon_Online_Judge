N = int(input())
s = []
ans = 0

for time in range(1, N+1):
    hw = input()
    if hw[0] == '0':
        if s:
            s[-1][1] -= 1
            if s[-1][1] == 0:
                ans += s[-1][0]
                s.pop()
    else:
        _, A, T = map(int, hw.split())
        if T == 1:
            ans += A
        else:
            s.append([A, T-1])

print(ans)
