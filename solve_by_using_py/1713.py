import heapq

N = int(input())
M = int(input())
like = list(map(int, input().split()))
q = []
for i in range(M):
    for item in q:
        if item[2] == like[i]:
            item[0] += 1
            heapq.heapify(q)
            break
    else:
        if len(q) == N:
            heapq.heappop(q)
        heapq.heappush(q, [1, i, like[i]])

q.sort(key=lambda x: x[2])
for num in q:
    print(num[2], end=' ')
