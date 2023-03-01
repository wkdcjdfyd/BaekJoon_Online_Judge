N = input()
idx = len(N) // 2

def half_reverse(s):
    reverse = ''
    for i in range(-1, -(len(s))-1, -1):
        reverse += s[i]

    return reverse

def is_all_nine(s):
    for i in s:
        if i != '9':
            return 0
    return 1

if len(N) % 2 == 0:
    new = N[:idx] + half_reverse(N[:idx])

    if int(N) < int(new):
        print(new)
    elif is_all_nine(N[:idx]):
        now = str(int(N[:idx])+1)
        new = now + half_reverse(now[:-1])
        print(new)
    else:
        now = str(int(N[:idx])+1)
        new = now + half_reverse(now)
        print(new)
else:
    new = N[:idx+1] + half_reverse(N[:idx])

    if int(N) < int(new):
        print(new)
    elif is_all_nine(N[:idx+1]):
        now = str(int(N[:idx+1])+1)[:idx+1]
        new = now + half_reverse(now)
        print(new)
    else:
        now = str(int(N[:idx+1])+1)
        new = now + half_reverse(now[:-1])
        print(new)