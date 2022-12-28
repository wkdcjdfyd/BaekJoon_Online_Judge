result = 0

for k, v in enumerate(input().split('-')):
    temp = 0
    for num in map(int, v.split('+')):
        temp += num
    if k == 0:
        result += temp
    else:
        result -= temp
print(result)
