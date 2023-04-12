N = int(input())
pa_front, pa_rear = input().split('*')

for i in range(N):
    filename = input()
    ans = 'DA'

    if len(pa_front) <= len(filename):
        for x in range(len(pa_front)):
            if pa_front[x] != filename[x]:
                ans = 'NE'
                break
    else:
        print('NE')
        continue

    idx = len(pa_front)

    if len(pa_rear) <= len(filename) - idx:
        x = 0
        length = len(pa_rear)
        file_length = len(filename)
        while x != length:
            x += 1
            if pa_rear[length-x] != filename[file_length-x]:
                ans = 'NE'
                break
    else:
        print('NE')
        continue

    print(ans)
