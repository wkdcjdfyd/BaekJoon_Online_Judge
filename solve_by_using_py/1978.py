def is_prime(x):
    if x == 1:
        return False
    for i in range(2, int((x**(1/2)))+1):
        if x % i == 0:
            return False
    else:
        return True

N = int(input())
arr = list(map(int, input().split()))
ans = 0
for n in arr:
    if is_prime(n):
        ans += 1

print(ans)
