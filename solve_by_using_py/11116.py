n = int(input())

for tc in range(n):
    m = int(input())
    l = list(map(int, input().split()))
    r = list(map(int, input().split()))

    cnt = 0
    for t in l:
        if t+500 in l and t+1000 in r and t+1500 in r:
            cnt += 1
    print(cnt)
