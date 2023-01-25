import sys

arr = [0] * (ord('z') - ord('a') + 1)

sen = sys.stdin.read().replace("\n","").replace(" ","")

for n in sen:
    arr[ord(n) - ord('a')] += 1

val = max(arr)

for k, v in enumerate(arr):
    if v == val:
        print(chr(k + ord('a')), end='')
