N, K = map(int, input().split())
height = list(map(int, input().split()))

height_sub = []
for i in range(1, N):
    height_sub.append(height[i]-height[i-1])

height_sub.sort(reverse=True)
print(sum(height_sub[K-1:]))
