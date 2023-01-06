N = int(input())
arr = list(map(int, input().split()))
d = [0] * N

for i in range(N):
    for j in range(i):
        if arr[i] > arr[j] and d[i] < d[j]:
            d[i] = d[j]
    d[i] += 1

print(max(d))
