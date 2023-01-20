A, B = map(int, input().split())

def is_last_one(x):
    if str(x)[-1] == '1':
        return True
    return False

cnt = 1
while A < B:
    if is_last_one(B):
        B = int(str(B)[:-1])
    else:
        if B % 2 == 0:
            B = B // 2
        else:
            cnt = -1
            break
    cnt += 1

if A > B:
    cnt = -1
print(cnt)
