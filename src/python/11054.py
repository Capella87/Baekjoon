# 백준 11054번 문제 : 가장 긴 바이토닉 부분 수열
# https://www.acmicpc.net/problem/11054
# 알고리즘 분류 : 다이나믹 프로그래밍

import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
cache = [0] * n
reversed_cache = [0] * n
result = 1

for i in range(0, n):
    cache[i] = 1
    for j in range(0, i + 1):
        if arr[j] < arr[i] and cache[i] < cache[j] + 1:
            cache[i] = cache[j] + 1
    rev_idx = n - 1 - i
    reversed_cache[rev_idx] = 1
    for j in range(n - 1, rev_idx - 1, -1):
        if arr[rev_idx] > arr[j] and reversed_cache[rev_idx] < reversed_cache[j] + 1:
            reversed_cache[rev_idx] = reversed_cache[j] + 1

for i in range(0, n):
    cache[i] += reversed_cache[i] - 1
    result = max(result, cache[i])

print(result)
