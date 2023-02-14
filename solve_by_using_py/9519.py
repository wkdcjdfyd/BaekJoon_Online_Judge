def rollback(word):
    front = 0
    rear = len(word)-1
    prev_word = [''] * len(word)

    for i in range(0, len(word), 2):
        prev_word[front] = word[i]
        front += 1
        if len(word) > i+1:
            prev_word[rear] = word[i+1]
            rear -= 1

    return ''.join(prev_word)

X = int(input())
word = input()
word_list = [word]

for _ in range(X):
    word = rollback(word)
    if word == word_list[0]:
        break
    word_list.append(word)

print(word_list[X % len(word_list)])
