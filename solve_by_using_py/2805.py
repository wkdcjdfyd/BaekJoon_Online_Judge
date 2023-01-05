import sys

N, M = map(int, sys.stdin.readline().strip().split())
arr = list(map(int, sys.stdin.readline().strip().split()))

start = 1
end = max(arr)

while start <= end:
    mid = (start + end) // 2
    res = 0

    for item in arr:
        if item > mid:
            res += item - mid

    if res >= M:
        start = mid + 1
    else:
        end = mid - 1

print(end)
