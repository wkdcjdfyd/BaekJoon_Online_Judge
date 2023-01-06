T = int(input())
quest = []

for testcase in range(T):
    quest.append(int(input()))

d = [0] * (max(quest) + 1)
d[1] = 1
d[2] = 2
d[3] = 4

for i in range(4, max(quest) + 1):
    d[i] = d[i-1] + d[i-2] + d[i-3]

for testcase in quest:
    print(d[testcase])
