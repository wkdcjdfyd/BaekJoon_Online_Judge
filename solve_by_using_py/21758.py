N = int(input())
idx = [x for x in range(N)]
arr = list(map(int, input().split()))
sub_sum = [arr[0]]
ans = 0

for i in range(1, N):
    sub_sum.append(sub_sum[i-1] + arr[i])

for i in range(1, N-1):
    ans = max(ans, 2 * sub_sum[-1] - arr[0] - sub_sum[i] - arr[i])
for i in range(1, N-1):
    ans = max(ans, sub_sum[-1] - arr[-1] - arr[i] + sub_sum[i - 1])
for i in range(1, N-1):
    ans = max(ans, sub_sum[i] - arr[0] + sub_sum[-1] - sub_sum[i-1] - arr[-1])

print(ans)
