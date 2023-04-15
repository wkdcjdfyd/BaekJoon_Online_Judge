import sys
from copy import deepcopy
input = sys.stdin.readline

N = int(input())
log = [[] for _ in range(N+1)]

for i in range(1, N+1):
    query = input().rstrip()

    if query[0] == 'a':
        num = int(query.split()[1])
        now = deepcopy(log[i-1])
        now.append(num)
        log[i] = now
        print(now[-1])
    elif query[0] == 's':
        now = deepcopy(log[i-1])
        if not now:
            print(-1)
        else:
            now = now[:-1]
            if not now:
                print(-1)
            else:
                print(now[-1])
            log[i] = now
    else:
        num = int(query.split()[1])
        now = deepcopy(log[num-1])
        if not now:
            print(-1)
        else:
            log[i] = now
            print(now[-1])
