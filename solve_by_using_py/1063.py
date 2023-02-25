k, s, n = input().split()
k_x, k_y = ord(k[0]), int(k[1])
s_x, s_y = ord(s[0]), int(s[1])

for _ in range(int(n)):
    order = input()

    if order == 'R':
        if k_x + 1 == ord('H') + 1:
            continue
        if k_y == s_y and k_x + 1 == s_x:
            if s_x + 1 == ord('H') + 1:
                continue
            else:
                s_x += 1
        k_x += 1
    elif order == 'L':
        if k_x - 1 == ord('A') - 1:
            continue
        if k_y == s_y and k_x - 1 == s_x:
            if s_x - 1 == ord('A') - 1:
                continue
            else:
                s_x -= 1
        k_x -= 1
    elif order == 'B':
        if k_y - 1 == 0:
            continue
        if k_x == s_x and k_y - 1 == s_y:
            if s_y - 1 == 0:
                continue
            else:
                s_y -= 1
        k_y -= 1
    elif order == 'T':
        if k_y + 1 == 9:
            continue
        if k_x == s_x and k_y + 1 == s_y:
            if s_y + 1 == 9:
                continue
            else:
                s_y += 1
        k_y += 1
    elif order == 'RT':
        if k_x + 1 == ord('H') + 1 or k_y + 1 == 9:
            continue
        if k_x + 1 == s_x and k_y + 1 == s_y:
            if s_x + 1 == ord('H') + 1 or s_y + 1 == 9:
                continue
            else:
                s_x += 1
                s_y += 1
        k_x += 1
        k_y += 1
    elif order == 'LT':
        if k_x - 1 == ord('A') - 1 or k_y + 1 == 9:
            continue
        if k_x - 1 == s_x and k_y + 1 == s_y:
            if s_x - 1 == ord('A') - 1 or s_y + 1 == 9:
                continue
            else:
                s_x -= 1
                s_y += 1
        k_x -= 1
        k_y += 1
    elif order == 'RB':
        if k_x + 1 == ord('H') + 1 or k_y - 1 == 0:
            continue
        if k_x + 1 == s_x and k_y - 1 == s_y:
            if s_x + 1 == ord('H') + 1 or s_y - 1 == 0:
                continue
            else:
                s_x += 1
                s_y -= 1
        k_x += 1
        k_y -= 1
    elif order == 'LB':
        if k_x - 1 == ord('A') - 1 or k_y - 1 == 0:
            continue
        if k_x - 1 == s_x and k_y - 1 == s_y:
            if s_x - 1 == ord('A') - 1 or s_y - 1 == 0:
                continue
            else:
                s_x -= 1
                s_y -= 1
        k_x -= 1
        k_y -= 1

K = chr(k_x)+str(k_y)
S = chr(s_x)+str(s_y)

print(K)
print(S)
