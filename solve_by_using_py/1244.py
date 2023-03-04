import sys
input = sys.stdin.readline

n = int(input())
sw = list(map(int, input().split()))

def on_off(s):
    if s == 0:
        return 1
    else:
        return 0

for _ in range(int(input())):
    sex, num = map(int, input().split())

    if sex == 1:
        for i in range(num-1, len(sw), num):
            sw[i] = on_off(sw[i])
    elif sex == 2:
        num -= 1
        sw[num] = on_off(sw[num])
        i = 1

        while 1:
            if num - i < 0 or num + i >= len(sw):
                break
            if sw[num-i] != sw[num+i]:
                break
            else:
                sw[num-i] = on_off(sw[num-i])
                sw[num+i] = on_off(sw[num+i])
                i += 1

for i in range(1, len(sw)+1):
    if i % 20 == 0:
        print(sw[i-1])
    else:
        print(sw[i-1], end=' ')
