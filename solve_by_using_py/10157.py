dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]

C, R = map(int, input().split())
K = int(input())

if K > C*R:
    print(0)
else:
    cnt = R
    R -= 1
    C -= 1
    x, y = 0, R

    if cnt >= K:
        y = y - (cnt - K)
    else:
        while cnt < K:
            x += 1
            y -= 1
            cnt += C + C - 1 + R + R - 1
            C -= 2
            R -= 2
        C += 1
        R += 1
        d = -1

        while cnt != K:
            d = (d+1) % 4

            if d % 2 == 0:
                if cnt - R < K:
                    y = y + dy[d] * (cnt - K)
                    break
                else:
                    y = y + dy[d] * R
                    cnt -= R
                    R += 1
            else:
                if cnt - C < K:
                    x = x + dx[d] * (cnt - K)
                    break
                else:
                    x = x + dx[d] * C
                    cnt -= C
                    C += 1
    print(x+1, y+1)
