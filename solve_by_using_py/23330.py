n = int(input())
x = sorted(list(map(int, input().split())), reverse=True)
ans = 0

for i in range(n):
    ans += (n-1-2*i) * x[i]

print(ans * 2)
