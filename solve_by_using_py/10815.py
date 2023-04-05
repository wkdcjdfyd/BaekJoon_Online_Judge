N = int(input())
card = sorted(list(map(int, input().split())))
M = int(input())
check_list = list(map(int, input().split()))

def binary_search(x):
    s, e = 0, N-1

    while s <= e:
        mid = (s + e) // 2

        if card[mid] == x:
            return 1
        elif card[mid] < x:
            s = mid + 1
        else:
            e = mid - 1
    return 0

for num in check_list:
    print(binary_search(num), end=' ')