import sys
input = sys.stdin.readline

def pick(cards, start, end):
    if dp[start][end] != 0:
        return dp[start][end]
    if start == end:
        dp[start][end] = [cards[start], 0]
        return dp[start][end]

    left_first, left_second = pick(cards, start+1, end)
    left_score = left_second + cards[start]
    right_first, right_second = pick(cards, start, end-1)
    right_score = right_second + cards[end]

    if left_score > right_score:
        dp[start][end] = [left_score, left_first]
    else:
        dp[start][end] = [right_score, right_first]

    return dp[start][end]

T = int(input())

for _ in range(T):
    N = int(input())
    dp = [[0 for _ in range(N)] for _ in range(N)]
    cards = list(map(int, input().split()))
    ans, _ = pick(cards, 0, N-1)
    print(ans)
