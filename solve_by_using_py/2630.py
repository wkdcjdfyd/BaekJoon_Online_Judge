N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]
blue = white = 0

def slicing(arr, x, y, a, b):
    result = []
    for row in arr[x:y]:
        result.append(row[a:b])
    return result

def div(arr, N):
    global blue
    global white
    if all(0 not in l for l in arr):
        blue += 1
        return
    elif all(1 not in l for l in arr):
        white += 1
        return

    next_N = int(N/2)

    arr1 = slicing(arr, 0, next_N, 0, next_N)
    arr2 = slicing(arr, 0, next_N, next_N, N)
    arr3 = slicing(arr, next_N, N, 0, next_N)
    arr4 = slicing(arr, next_N, N, next_N, N)

    arr_list = [arr1, arr2, arr3, arr4]
    for item in arr_list:
        if all(0 not in l for l in item):
            blue += 1
        elif all(1 not in l for l in item):
            white += 1
        else:
            div(item, next_N)


div(arr, N)
print(white)
print(blue)
