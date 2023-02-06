N = int(input())
house_loc = sorted(list(map(int, input().split())))
print(house_loc[(N-1)//2])
