import sys
input = sys.stdin.readline

for tc in range(int(input())):
    stone = list(map(int, input().split()))
    odd_cnt, even_cnt = 0, 0

    for s in stone:
        if s % 2 == 0:
            even_cnt += 1
        else:
            odd_cnt += 1

    if odd_cnt == 2 or odd_cnt == 3:
        print('B')
    else:
        print('R')
