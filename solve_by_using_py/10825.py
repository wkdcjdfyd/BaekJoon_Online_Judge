from functools import cmp_to_key

def comparator(a, b):
    if a[1] < b[1]:
        return 1
    elif a[1] == b[1]:
        if a[2] > b[2]:
            return 1
        elif a[2] == b[2]:
            if a[3] < b[3]:
                return 1
            elif a[3] == b[3]:
                if a[0] > b[0]:
                    return 1
                else:
                    return -1
            else:
                return -1
        else:
            return -1
    else:
        return -1

N = int(input())
data = []

for _ in range(N):
    input_data = input().split()
    data.append([input_data[0], int(input_data[1]), int(input_data[2]), int(input_data[3])])

sorted_data = sorted(data, key=cmp_to_key(comparator))

for item in sorted_data:
    print(item[0])
