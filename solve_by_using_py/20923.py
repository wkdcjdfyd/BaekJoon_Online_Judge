import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())

do_deck = deque()
su_deck = deque()

for _ in range(N):
    c1, c2 = map(int, input().split())
    do_deck.appendleft(c1)
    su_deck.appendleft(c2)

do_ground = []
su_ground = []
turn = 1
for _ in range(M):
    su_win = 0
    if turn == 1:
        card = do_deck.popleft()
        if len(do_deck) == 0:
            print('su')
            break
        do_ground.append(card)
        if len(su_ground) != 0 and card + su_ground[-1] == 5:
            su_win = 1
    else:
        card = su_deck.popleft()
        if len(su_deck) == 0:
            print('do')
            break
        su_ground.append(card)
        if len(do_ground) != 0 and card + do_ground[-1] == 5:
            su_win = 1
    if card == 5:
        do_deck.extend(su_ground)
        do_deck.extend(do_ground)
        su_ground = []
        do_ground = []
    elif su_win == 1:
        su_deck.extend(do_ground)
        su_deck.extend(su_ground)
        do_ground = []
        su_ground = []

    turn *= -1
else:
    if len(do_deck) > len(su_deck):
        print('do')
    elif len(do_deck) < len(su_deck):
        print('su')
    else:
        print('dosu')
