N = int(input())
liq = list(map(int, input().split()))
l_idx = 0
r_idx = N-1

ans = abs(liq[l_idx] + liq[r_idx])
ans_left = l_idx
ans_right = r_idx

while l_idx < r_idx:
    val = liq[l_idx] + liq[r_idx]

    if abs(val) < ans:
        ans_left = l_idx
        ans_right = r_idx
        ans = abs(val)

        if not ans:
            break

    if val < 0:
        l_idx += 1
    else:
        r_idx -= 1

print(liq[ans_left], liq[ans_right])
