N, K = map(int, input().split())
test_paper = list(map(int, input().split()))

def binary_search(s, e):
    ans = 0
    while s <= e:
        mid = (s + e) // 2
        group = 0
        score = 0
        for sc in test_paper:
            score += sc
            if score >= mid:
                group += 1
                score = 0
        if group >= K:
            ans = mid
            s =  mid + 1
        else:
            e = mid - 1
    print(ans)

binary_search(0, int(1e5) * 20 + 1)
