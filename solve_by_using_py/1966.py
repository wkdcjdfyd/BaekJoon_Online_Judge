import queue

for testcase in range(int(input())):
    q = queue.Queue()
    N, M = map(int, input().split())
    items = list(map(int, input().split()))
    max_val = max(items)
    max_val_idx = items.index(max_val)
    result = 0

    for item in items:
        q.put(item)

    while not q.empty():
        now = q.get()
        if now == max_val:
            result += 1

            if M == 0:
                print(result)
                break
            else:
                items.pop(max_val_idx)
                max_val = max(items)
                max_val_idx = items.index(max_val)
        else:
            q.put(now)

        if M == 0:
            M = q.qsize() - 1
        else:
            M -= 1
