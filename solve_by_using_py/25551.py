wm, bm = map(int, input().split())
wt, bt = map(int, input().split())
wp, bp = map(int, input().split())

x = min(wm, bt, wp)
y = min(bm, wt, bp)

if abs(x-y) >= 2:
    print(min(x, y) * 2 + 1)
else:
    print(x+y)
