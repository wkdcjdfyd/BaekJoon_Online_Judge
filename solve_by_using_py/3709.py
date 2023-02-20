T = int(input())

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

for _ in range(T):
    n, r = map(int, input().split())
    loc = [list(map(int, input().split())) for _ in range(r)]
    l_x, l_y = map(int, input().split())
    
    # 레이저 시작점으로부터의 진행방향
    if l_x > n:
        d = 0
    elif l_y == 0:
        d = 1
    elif l_x == 0:
        d = 2
    else:
        d = 3
    x = l_x + dx[d]
    y = l_y + dy[d]

    his = []
    cir_flag = 0
    while 1:
        if x == 0 or x == n+1 or y == 0 or y == n+1:
            print(x, y)
            break
        for mir_x, mir_y in loc:
            if x == mir_x and y == mir_y:
                if (mir_x, mir_y, d) in his:
                   cir_flag = 1
                   break

                his.append((mir_x, mir_y, d))
                d = (d+1) % 4
                break
        if cir_flag:
            print(0, 0)
            break
        x = x + dx[d]
        y = y + dy[d]
