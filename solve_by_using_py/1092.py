N = int(input())
crain = sorted(list(map(int, input().split())), reverse=True)
M = int(input())
box = sorted(list(map(int, input().split())), reverse=True)
last_moved = [-1] * N
visited = [0] * M

def binary_search(x):
    s, e = 0, M-1

    while s <= e:
        mid = (s+e) // 2
        if box[mid] > x:
            s = mid + 1
        else:
            e = mid - 1
    return mid

if crain[0] < box[0]:
    print(-1)
else:
    time = 0
    move_cnt = 0

    while move_cnt != M:
        for i in range(N):
            if last_moved[i] == -1:
                for j in range(binary_search(crain[i]), M):
                    if box[j] <= crain[i] and visited[j] == 0:
                        visited[j] = 1
                        last_moved[i] = j
                        move_cnt += 1
                        break
            else:
                for j in range(last_moved[i]+1, M):
                    if box[j] <= crain[i] and visited[j] == 0:
                        visited[j] = 1
                        last_moved[i] = j
                        move_cnt += 1
                        break
            if move_cnt == M:
                break
        time += 1

    print(time)
