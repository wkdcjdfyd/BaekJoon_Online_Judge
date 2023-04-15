from collections import deque
from copy import deepcopy

T = int(input())

for tc in range(T):
    h, l = map(int, input().split())
    ans = 0

    for i in range(h):
        car = list(map(int, input().split()))
        q = deque(car)
        order = sorted(deepcopy(car))
        cnt = 0
        blank_cnt = 0

        for o in order:
            if o == -1:
                blank_cnt += 1
                continue
            idx = q.index(o)

            if idx < l - idx:
                while q:
                    now = q.popleft()

                    if now == o:
                        q.appendleft(-1)
                        break
                    cnt += 1
                    q.append(now)
            else:
                while q:
                    now = q.pop()
                    cnt += 1
                    if now == o:
                        q.appendleft(-1)
                        break
                    q.appendleft(now)

        ans += cnt * 5 + (len(order) - blank_cnt) * 20 * i

    print(ans)
