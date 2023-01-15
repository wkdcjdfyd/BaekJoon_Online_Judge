import sys
import heapq

input = sys.stdin.readline
T = int(input())

for t in range(T):
    min_heap = []
    max_heap = []
    K = int(input())
    visited = [False] * K
    for k in range(K):
        order, val = input().split()
        if order == 'I':
            heapq.heappush(min_heap, (int(val), k))
            heapq.heappush(max_heap, (int(val) * -1, k))
            visited[k] = True
        elif order == 'D':
            if int(val) == -1:
                while min_heap and not visited[min_heap[0][1]]:
                    heapq.heappop(min_heap)
                if min_heap:
                    visited[min_heap[0][1]] = False
                    heapq.heappop(min_heap)
            elif int(val) == 1:
                while max_heap and not visited[max_heap[0][1]]:
                    heapq.heappop(max_heap)
                if max_heap:
                    visited[max_heap[0][1]] = False
                    heapq.heappop(max_heap)
    while min_heap and not visited[min_heap[0][1]]:
        heapq.heappop(min_heap)
    while max_heap and not visited[max_heap[0][1]]:
        heapq.heappop(max_heap)

    if min_heap and max_heap:
        print(-max_heap[0][0], min_heap[0][0])
    else:
        print('EMPTY')
