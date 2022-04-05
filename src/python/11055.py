# 백준 11055번 문제 : 가장 큰 증가 부분 수열
# https://www.acmicpc.net/problem/11055
# 알고리즘 분류 : 다이나믹 프로그래밍

import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split(' ')))
cache = [0] * n
cache[0] = arr[0]

max_cache = arr[0]
for i in range(1, n):
    max_sum = 0
    for j in range(0, i):
        if arr[j] < arr[i] and max_sum < cache[j]:
            max_sum = cache[j]
    cache[i] = arr[i] + max_sum
    max_cache = max(max_cache, cache[i])

print(max_cache)
