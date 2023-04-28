inning1 = list(map(int, input().split()))
inning2 = list(map(int, input().split()))

ans_flag = 0
score1, score2 = 0, 0

for i in range(9):
    score1 += inning1[i]
    if score1 > score2:
        ans_flag = 1

    score2 += inning2[i]
    if score1 > score2:
        ans_flag = 1

if score1 < score2 and ans_flag == 1:
    print('Yes')
else:
    print('No')
