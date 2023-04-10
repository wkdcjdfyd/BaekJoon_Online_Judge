A, B = map(int, input().split())
ans = 0
num = 1
num_cnt = 0

for n in range(1, B+1):
    if n >= A:
        ans += num
    num_cnt += 1
    if num == num_cnt:
        num += 1
        num_cnt = 0
print(ans)
