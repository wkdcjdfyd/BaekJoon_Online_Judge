board = list(input().rstrip())
i = 0

while i < len(board):
    if board[i] == '.':
        i += 1
        continue

    temp = i+1
    cnt = 1
    while temp < len(board):
        if board[temp] == 'X':
            temp += 1
            cnt += 1
        else:
            break

    while cnt > 0:
        if cnt == 1:
            print(-1)
            exit()
        if cnt > 3:
            board[i:i+4] = 'AAAA'
            cnt -= 4
            i += 4
            continue
        elif cnt > 1:
            board[i:i+2] = 'BB'
            cnt -= 2
            i += 2
            continue
print(''.join(board))
