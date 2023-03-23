import sys
input = sys.stdin.readline

N = int(input())
ball = []
sub_sum = [[-1, -1] for _ in range(N)]
now = {}

for i in range(N):
    C, S = map(int, input().split())
    ball.append([i, C, S])

ball.sort(key=lambda x: x[2])
prev = 0

for i in range(N):
    idx, c, s = ball[i]

    if i == 0:
        sub_sum[i] = [idx, 0]
        now[c] = s
    else:
        n = now.get(c, None)
        prev += ball[i - 1][2]
        if ball[i-1][2] == s:
            temp = 0
            for j in range(i-1, -1, -1):
                if ball[j][2] != s:
                    break
                if ball[j][1] == c:
                    continue
                temp += s
            sub_sum[i] = [idx, prev - temp]
        if n is None:
            now[c] = s
            if sub_sum[i][1] == -1:
                sub_sum[i] = [idx, prev]
        else:
            if sub_sum[i][1] == -1:
                sub_sum[i] = [idx, prev - now[c]]
            else:
                sub_sum[i][1] -= now[c]
            now[c] += s

sub_sum.sort(key=lambda x: x[0])
for i in range(N):
    print(sub_sum[i][1])