def reverse(word):
    rev_word = list(word)
    rev_word.reverse()
    return ''.join(rev_word)

S = input().rstrip()

print_idx = 0
special_flag = 0
for i in range(len(S)):
    if S[i] == '<':
        print(reverse(S[print_idx:i]), end='')
        print_idx = i
        special_flag = 1
    elif S[i] ==  '>':
        print(S[print_idx:i+1], end='')
        print_idx = i+1
        special_flag = 0
    elif S[i] == ' ' and special_flag == 0:
        print(reverse(S[print_idx:i]), end=' ')
        print_idx = i+1
if S[len(S)-1] != '>':
    print(reverse(S[print_idx:len(S)]), end='')
