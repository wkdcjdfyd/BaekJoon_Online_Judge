arr = [x for x in range(1, 21)]

def reverse(a, b):
    temp = [0] * (b-a+1)

    now = 0
    for i in range(b-1, a-2, -1):
        temp[now] = arr[i]
        now += 1
    arr[a-1:b] = temp

for i in range(10):
    a, b = map(int, input().split())
    reverse(a, b)
print(*arr)
