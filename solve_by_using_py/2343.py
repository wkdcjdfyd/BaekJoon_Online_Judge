N, M = map(int, input().split())
arr = list(map(int, input().split()))

start = max(arr)
end = sum(arr)

while start <= end:
    mid = (start + end) // 2
    cnt = 0
    record_sum = 0

    for record in arr:
        if record_sum + record > mid:
            cnt += 1
            record_sum = 0
        record_sum += record
    if record_sum:
        cnt += 1

    if cnt <= M:
        end = mid - 1
    else:
        start = mid + 1

print(start)