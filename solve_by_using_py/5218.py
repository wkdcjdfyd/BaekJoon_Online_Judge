def dist(a, b):
    A = ord(a) - ord('A') + 1
    B = ord(b) - ord('A') + 1
    if A <= B:
        return B - A
    else:
        return B + 26 - A

for _ in range(int(input())):
    x, y = input().split()

    print("Distances: ", end='')
    for i in range(len(x)):
        print(dist(x[i], y[i]), end=' ')
    print()
