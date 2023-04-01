N = int(input())
K = int(input())
sensor = sorted(list(map(int, input().split())))

if K >= N:
    print(0)
else:
    sensor.sort()
    dist = sorted([sensor[x+1] - sensor[x] for x in range(N-1)], reverse=True)

    print(sum(dist[K-1:]))
