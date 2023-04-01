N = int(input())
K = int(input())
sensor = list(map(int, input().split()))

if K >= N:
    print(0)
else:
    sensor.sort()
    dist = [sensor[x+1] - sensor[x] for x in range(N-1)]
    dist.sort(reverse=True)

    for _ in range(K-1):
        dist.pop(0)

    print(sum(dist))
