import sys
input = sys.stdin.readline

N, M = map(int, input().split())
schedule = list(map(int, input().split()))
train_cnt = [0] * (N+1)

for j in range(M-1):
    start, end = schedule[j], schedule[j+1]
    if start < end:
        train_cnt[start] += 1
        train_cnt[end] -= 1
    else:
        train_cnt[end] += 1
        train_cnt[start] -= 1

ans = 0
sub_sum = 0
for i in range(1, N):
    A, B, C = map(int, input().split())
    sub_sum += train_cnt[i]
    ticket_cost = A * sub_sum
    card_cost = (B * sub_sum) + C

    if ticket_cost < card_cost:
        ans += ticket_cost
    else:
        ans += card_cost

print(ans)
