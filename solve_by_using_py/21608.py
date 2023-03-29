import sys
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
score = [0, 1, 10, 100, 1000]

N = int(input())
graph = [[0] * N for _ in range(N)]
love = [[] for _ in range((N**2) + 1)]
order = []

for _ in range(N**2):
    temp = list(map(int, input().split()))
    love[temp[0]].extend(temp[1:])
    order.append(temp[0])

def find_seat(now):
    loc = [-1, -1]
    cnt = [-1, -1]

    for x in range(N):
        for y in range(N):
            # 비어있지 않으면 pass
            if graph[x][y] != 0:
                continue

            # 비어있다면 인접한 칸에 좋아하는 학생, 빈 칸 개수 세기
            love_cnt = 0
            blank_cnt = 0
            for d in range(4):
                nx = x + dx[d]
                ny = y + dy[d]
                if 0 <= nx < N and 0 <= ny < N:
                    if graph[nx][ny] in love[now]:
                        love_cnt += 1
                    elif graph[nx][ny] == 0:
                        blank_cnt += 1

            if cnt[0] < love_cnt:
                loc = [x, y]
                cnt = [love_cnt, blank_cnt]
            elif cnt[0] == love_cnt:
                if cnt[1] < blank_cnt:
                    loc = [x, y]
                    cnt = [love_cnt, blank_cnt]
                elif cnt[1] == blank_cnt:
                    if x < loc[0]:
                        loc = [x, y]
                        cnt = [love_cnt, blank_cnt]
                    elif x == loc[0] and y < loc[1]:
                        loc = [x, y]
                        cnt = [love_cnt, blank_cnt]
    return loc

def get_point():
    point = 0
    for x in range(N):
        for y in range(N):
            cnt = 0
            for d in range(4):
                nx = x + dx[d]
                ny = y + dy[d]
                if 0 <= nx < N and 0 <= ny < N:
                    if graph[nx][ny] in love[graph[x][y]]:
                        cnt += 1
            point += score[cnt]
    return point

for now in order:
    x, y = find_seat(now)
    graph[x][y] = now

print(get_point())
