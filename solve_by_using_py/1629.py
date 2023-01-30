import sys
A, B, C = map(int, sys.stdin.readline().split())

def mul(a, b):
    if b == 1:
        return a % C
    else:
        pre_a = a
        a = mul(a, b // 2)
        if b % 2 == 0:
            return (a * a) % C
        else:
            return (a * a * pre_a) % C

print(mul(A, B))
