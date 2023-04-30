T = int(input())

for _ in range(T):
    n = int(input())
    before = sorted(list(input().split()))
    after = sorted(list(input().split()))

    for b in before:
        if b in after:
            idx = after.index(b)
            after.pop(idx)
        else:
            print("CHEATER")
            break
    else:
        print("NOT CHEATER")
