N = int(input())
arr = list(map(int, input().split()))
M = int(input())

start = 1
end = max(arr)

while start <= end:
    mid = (start + end) // 2
    now = 0

    for item in arr:
        if mid < item:
            now += mid
        else:
            now += item

    if now > M:
        end = mid - 1
    else:
        start = mid + 1

print(end)