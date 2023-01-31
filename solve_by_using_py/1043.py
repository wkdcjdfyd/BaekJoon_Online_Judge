import sys
input = sys.stdin.readline

N, M = map(int, input().split())
truth = input()
truth_num = int(truth[0])
ans = 0

if not truth_num:
    print(M)
    exit()
else:
    truth = list(map(int, truth.split()))
    truth.pop(0)
    truth = set(truth)

party_mem = []
for _ in range(M):
    mem = list(map(int, input().split()))
    mem.pop(0)
    party_mem.append(mem)


while 1:
    for idx, mem in enumerate(party_mem):
        flag = 0
        for num in truth:
            if num in mem:
                flag = 1
                break
        if flag:
            truth.update(set(mem))
            party_mem.pop(idx)
            break
    if not flag or not len(party_mem):
        print(len(party_mem))
        break
