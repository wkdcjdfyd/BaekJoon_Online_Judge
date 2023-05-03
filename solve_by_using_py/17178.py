N = int(input())
graph = []

for _ in range(N):
    temp = list(input().split())
    new = []
    for x in temp:
        a, b = x.split('-')
        new.append([a, int(b)])
    graph.extend(new)

order = sorted(graph)

wait = []
order_num = 0
idx = 0

while order_num != len(order):
    if idx >= len(graph):
        if order[order_num] == wait[-1]:
            wait.pop()
            order_num += 1
        else:
            print("BAD")
            break
    elif order[order_num] == graph[idx]:
        order_num += 1
        idx += 1
    elif wait and order[order_num] == wait[-1]:
        wait.pop()
        order_num += 1
    else:
        wait.append(graph[idx])
        idx += 1
else:
    print("GOOD")

