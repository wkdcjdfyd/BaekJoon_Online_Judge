N = int(input())
boys = []
girls = []

for i in range(0, 3):
    x, y = map(int, input().split())
    boys.append(x)
    girls.append(y)

for i in range(0, boys[0] + 1):
    A_B = i
    A_C = boys[0] - A_B
    B_C = girls[2] - A_C
    B_A = boys[1] - B_C
    C_A = girls[0] - B_A
    C_B = boys[2] - C_A


    if A_B >= 0 and A_C >= 0 and B_A >= 0 and B_C >= 0 and C_A >= 0 and C_B >= 0:
        print(1)
        print(A_B, A_C)
        print(B_A, B_C)
        print(C_A, C_B)
        break
else:
    print(0)
