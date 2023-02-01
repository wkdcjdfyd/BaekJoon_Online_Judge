word1 = input()
word2 = input()

arr = [[0] * (len(word2)+1) for _ in range(len(word1)+1)]

for i in range(1, len(word1)+1):
    for j in range(1, len(word2)+1):
        if word1[i-1] == word2[j-1]:
            arr[i][j] = arr[i-1][j-1] + 1
        else:
            arr[i][j] = max(arr[i-1][j], arr[i][j-1])

print(max(map(max, arr)))
