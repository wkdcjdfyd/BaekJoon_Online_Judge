M = int(input())
arr = [1, 2, 3]

for _ in range(M):
    X, Y = map(int, input().strip().split())
    idx1 = arr.index(X)
    idx2 = arr.index(Y)
    arr[idx1], arr[idx2] = arr[idx2], arr[idx1]

print(arr[0])
