N = int(input())
data = []

for _ in range(N):
    data.append(list(map(int, input().split())))

data.sort(key=lambda x: (x[1], x[0]))

for item in data:
    print(item[0], item[1])
