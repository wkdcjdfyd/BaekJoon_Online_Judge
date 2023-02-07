import math

N, M, L = map(int, input().split())

if not N:
    print(math.ceil(L/(M+1)))
    exit()

loc = sorted(list(map(int, input().split())))
sub_loc = []
for i in range(len(loc)):
    if i == 0:
        sub_loc.append(loc[i])
    else:
        sub_loc.append(loc[i]-loc[i-1])
sub_loc.append(L-loc[-1])

sub_loc.sort()

def binary_search():
    s = 1
    e = L-1

    while s < e:
        mid = (s + e) // 2
        cnt = 0
        for val in sub_loc:
            if val > mid:
                if val % mid == 0:
                    cnt += (val // mid) - 1
                else:
                    cnt += val // mid

        if cnt <= M:
            e = mid
        else:
            s = mid+1
    print(e)

binary_search()
