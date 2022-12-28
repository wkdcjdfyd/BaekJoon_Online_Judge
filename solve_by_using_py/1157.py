import sys

word = sys.stdin.readline().strip().upper()
word_dict = {}
max_val = -10000
max_n = ''

if not word:
    print('?')

for n in word:
    val = word_dict.get(n, -1)
    if val == -1:
        word_dict[n] = 1
    else:
        word_dict[n] += 1

sorted_dict = sorted(word_dict.items(), key=lambda item: item[1], reverse=True)
if len(sorted_dict) > 1 and sorted_dict[0][1] == sorted_dict[1][1]:
    print('?')
else:
    print(sorted_dict[0][0])
