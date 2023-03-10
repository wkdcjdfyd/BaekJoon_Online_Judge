import sys
input = sys.stdin.readline

visited = [[0]* 6 for _ in range(6)]

dx = [1, 1, -1, -1, 2, 2, -2, -2]
dy = [2, -2, 2, -2, 1, -1, 1, -1]

x, y = input().rstrip()
x = ord(x) - ord('A')
y = int(y) - 1
visited[x][y] = 1
start_x, start_y = x, y

for _ in range(35):
    nx, ny = input().rstrip()
    nx = ord(nx) - ord('A')
    ny = int(ny) - 1

    for i in range(8):
        temp_x = x + dx[i]
        temp_y = y + dy[i]
        if temp_x < 0 or temp_y < 0 or temp_x >= 6 or temp_y >= 6:
            continue
        if temp_x == nx and temp_y == ny:
            if visited[nx][ny] != 0 :
                print('Invalid')
                exit()
            x, y = nx, ny
            visited[x][y] = 1
            break
    else:
        print('Invalid')
        exit()

for i in range(8):
    temp_x = x + dx[i]
    temp_y = y + dy[i]
    if temp_x < 0 or temp_y < 0 or temp_x >= 6 or temp_y >= 6:
        continue
    if temp_x == start_x and temp_y == start_y:
        print('Valid')
        exit()
else:
    print('Invalid')