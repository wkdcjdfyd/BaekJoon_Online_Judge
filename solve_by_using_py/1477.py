import math

N, M, L = map(int, input().split())

if not N:
    print(math.ceil(L/(M+1)))
    exit()

loc = sorted(list(map(int, input().split())))
sub_loc = [loc[0]] + [loc[i]-loc[i-1] for i in range(1, len(loc))] + [L-loc[-1]]

def binary_search():
    s = 1
    e = L-1

    while s < e:
        mid = (s + e) // 2
        cnt = 0
        for val in sub_loc:
            cnt += (val-1) // mid
        if cnt <= M:
            e = mid
        else:
            s = mid+1
    print(e)

binary_search()
