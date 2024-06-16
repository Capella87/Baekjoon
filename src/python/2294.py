# 백준 2294번 문제 : 동전 2
# https://www.acmicpc.net/problem/2294
# 알고리즘 분류 : 다이나믹 프로그래밍

# Bottom-up approach

import sys


n, k = map(int, sys.stdin.readline().split(' '))
coins = [int(sys.stdin.readline()) for _ in range(n)]
cache = [1000000] * (k + 1)
cache[0] = 0

for i in range(1, k + 1):
    # Try all coins to make i and get the minimum number of coins to make
    for j in range(0, n):
        if coins[j] <= i:
            cache[i] = min(cache[i], 1 + cache[i - coins[j]])
print(-1 if cache[k] == 1000000 else cache[k])
