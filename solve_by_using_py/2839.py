N = int(input())
result = 0

while N >= 0:
    if N % 5 == 0:
        print(result + N // 5)
        exit()
    N -= 3
    result += 1
print(-1)
