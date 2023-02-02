def is_prime(n):
    if n == 1:
        return False
    for i in range(1, int(n**(1/2))+1):
        if i == 1:
            continue
        elif n % i == 0:
            return False
    return True

M, N = map(int, input().split())

for num in range(M, N+1):
    if is_prime(num):
        print(num)
