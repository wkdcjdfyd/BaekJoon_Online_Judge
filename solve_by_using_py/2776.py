import sys

T = int(input())

for _ in range(T):
    N = int(input())
    n_data = sys.stdin.readline().strip()
    n_data = set(map(int, n_data.split()))
    M = int(input())
    m_data = sys.stdin.readline().strip()
    m_data = list(map(int, m_data.split()))

    for item in m_data:
        print(1) if item in n_data else print(0)
