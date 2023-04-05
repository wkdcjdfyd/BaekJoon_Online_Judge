N = int(input())
DP = [0] * 31

DP[1]=1
DP[2]=3

for i in range(3, N+1):
    DP[i] = DP[i-1] + 2*DP[i-2]

if N >= 3:
    if N % 2 == 0:
        print((DP[N] - (2*DP[(N-2)//2] + DP[N//2]))//2 + (2*DP[(N-2)//2] + DP[N//2]))
    else:
        print((DP[N] - DP[(N-1)//2])//2 + DP[(N-1)//2])
else:
    print(DP[N])